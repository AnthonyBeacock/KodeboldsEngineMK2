

struct DirectionalLight
{
	float3 direction;
	float4 colour;
};

struct Pointlight
{
	float4 position;
	float4 colour;

	float range;
};


//--------------------------------------------------------------------------------------
// Constant Buffer Variables
//--------------------------------------------------------------------------------------
cbuffer ConstantBuffer : register(b0)
{
	float4x4 World;
	float4x4 View;
	float4x4 Projection;
	float4 CameraPosition;
	float4 Colour;
	float Time;
	float3 padding3;
}

//A lighting buffer would be nice, could do with setting ambient light in here too

cbuffer LightingBuffer : register (b1)
{
	float numDirLights;
	float3 padding4;
	DirectionalLight dirLights[2];

	float numPointLights; //5 max
	float3 padding5;
	Pointlight pointLights[5];
}

Texture2D txDiffuse : register(t0);
SamplerState txDiffSampler : register(s0);

Texture2D txBump : register(t1);
SamplerState txBumpSampler : register(s1);


//--------------------------------------------------------------------------------------
// Shader Inputs
//--------------------------------------------------------------------------------------
struct VS_INPUT
{
	float3 Pos : POSITION;
	float3 Normal : NORMAL;
	//float3 Tangent : TANGENT;
	//float3 Binormal : BINORMAL;
	float2 TexCoord : TEXCOORD0;
	//float3 InstancePos : INSTANCEPOS;
};

struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float3 Normal: NORMAL;
	float4 PosWorld : TEXCOORD0;
	float2 TexCoord : TEXCOORD1;
	float4 ParticleColour : TECXOORD2;
};


//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
PS_INPUT VS(VS_INPUT input)
{
	PS_INPUT output = (PS_INPUT)0;

	input.Pos.xyz = input.Pos.zyx;
	output.PosWorld = mul(float4(input.Pos, 1.0f), World);

	float index = abs(input.Pos.z);

	output.ParticleColour = 1 - index.rrrr;
	output.ParticleColour.a = 0.75;

	float4x4 ViewT = transpose(View);

	float3 viewLeft = ViewT._m00_m01_m02;
	float3 viewUp = ViewT._m10_m11_m12;
	float3 viewFwd = ViewT._m21_m23_m33;

	float4 inPos = float4(input.Pos, 1);
	float ttl = 1;
	float lifeTime = ttl - ((Time + index) % ttl);

	inPos.xy = inPos.xy * 4 * (1 - lifeTime);// *input.Scale.xy;

	float pi = 3.14159265359;

	float turn = ((pi * 2) / 100) * (index * 5937);

	float radius = 10.5;
	float3 animPos;

	animPos.x = sin(turn + Time) * radius * (1 - lifeTime);
	animPos.y = cos(turn + Time) * radius * (1 - lifeTime);
	animPos.z = ((1 - lifeTime) * -250); //sin(inPos.z * 1000 + time);

	//animPos = mul(float4(animPos, 1), input.RotationMatrix);

	inPos.z = 0;
	
	inPos.xyz = output.PosWorld.xyz + animPos + inPos.x * viewLeft + inPos.y*viewUp + abs(inPos.z) * viewFwd;

	output.Pos = inPos;

	output.Pos = mul(output.Pos, View);
	output.Pos = mul(output.Pos, Projection);

	/*output.Pos = mul(float4(input.Pos, 1.0f), World);
	output.Pos = mul(output.Pos, View);
	output.Pos = mul(output.Pos, Projection);
	output.Normal = mul(World, float4(input.Normal, 1.0f)).xyz;
	output.Normal = normalize(output.Normal);*/
	output.TexCoord = input.TexCoord;

	float4x4 worldViewMatrix = mul(World, View);
	float3 positionVS = input.Pos + float3(worldViewMatrix._41, worldViewMatrix._42, worldViewMatrix._43);
	output.Pos = mul(float4(positionVS, 1.0f), Projection);

	return output;
}

float4 CalcLightColour(float4 matDiffuse, float4 matSpec, float3 viewDirection, float3 lightDir, float4 lightColour, PS_INPUT input)
{
	float diffuse = max(0.0, dot(lightDir, input.Normal));
	float3 R = normalize(reflect(-lightDir, input.Normal));
	float spec = pow(max(0.0, dot(viewDirection, R)), 50);

	return (lightColour * matDiffuse * diffuse) + (lightColour * matSpec * spec);
}

float3x3 cotangent_frame(float3 N, float3 p, float2 uv)
{
	// get edge vectors of the pixel triangle
	float3 dp1 = ddx(p);
	float3 dp2 = ddy(p);
	float2 duv1 = ddx(uv);
	float2 duv2 = ddy(uv);

	// solve the linear system
	float3 dp2perp = cross(dp2, N);
	float3 dp1perp = cross(N, dp1);
	float3 T = dp2perp * duv1.x + dp1perp * duv2.x;
	float3 B = dp2perp * duv1.y + dp1perp * duv2.y;

	// construct a scale-invariant frame 
	float invmax = rsqrt(max(dot(T, T), dot(B, B)));
	return transpose(float3x3(T * invmax, B * invmax, N));
}

float3 perturb_normal(float3 N, float3 V, float2 texcoord)
{
	// assume N, the interpolated vertex normal and 
	// V, the view vector (vertex to eye)
	float3 map = txBump.Sample(txBumpSampler, texcoord).xyz; 
	////float4 texColour = txDiffuse.Sample(txSampler, input.TexCoord);

	//map.y = -map.y;
	float3x3 TBN = cotangent_frame(N, -V, texcoord);
	return normalize(mul(TBN, map));
}


//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS(PS_INPUT input) : SV_Target
{
	//Load texture pixels
	//Apply colour modification
	//return

	return input.ParticleColour;

	float distFromCentre = 1 - saturate(distance(float2(0.5, 0.5), input.TexCoord));
return float4(distFromCentre.rrrr);// , 1);
}
