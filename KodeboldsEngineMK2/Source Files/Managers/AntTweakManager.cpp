#include "AntTweakManager.h"

/// <summary>
/// Default constructor
/// </summary>
AntTweakManager::AntTweakManager()
{
}

/// <summary>
/// Default destructor
/// </summary>
AntTweakManager::~AntTweakManager()
{
}

/// <summary>
/// Creates a singleton instance of AntTweak Manager if one hasn't been created before
/// Returns pointer to the instance of AntTweak Manager
/// </summary>
/// <returns>Shared pointer to the AntTweak Manager instance</returns>
std::shared_ptr<AntTweakManager> AntTweakManager::Instance()
{
	static std::shared_ptr<AntTweakManager> instance{ new AntTweakManager };
	return instance;
}

/// <summary>
/// Initialises anttweak GUI
/// </summary>
/// <param name="graphicsAPI">Graphics API used in application</param>
/// <param name="pDevice">Pointer to graphics device</param>
/// <param name="width">Width of window</param>
/// <param name="height">Height of window</param>
void AntTweakManager::Init(const TwGraphAPI& pGraphicsAPI, void* const pDevice, const int pWidth, const int pHeight) const
{
	TwInit(pGraphicsAPI, pDevice);
	TwWindowSize(pWidth, pHeight);
}

/// <summary>
/// Adds a bar to the anttweak GUI
/// </summary>
/// <param name="barName">Name of bar to be added</param>
void AntTweakManager::AddBar(const std::string& pBarName)
{
	TwBar* newBar = TwNewBar(pBarName.c_str());
	mBars.emplace_back(std::make_pair(pBarName, newBar));
}

/// <summary>
/// Adds a variable to the anttweak GUI
/// </summary>
/// <param name="barName">Name of the bar to hold the variable</param>
/// <param name="variableName">Name of the variable to be added</param>
/// <param name="variableType">Type of the variable to be added</param>
/// <param name="variable">Pointer to the variable to be added</param>
/// <param name="behaviourDefinition">Anttweak behaviour definition string</param>
void AntTweakManager::AddVariable(const std::string& pBarName, const std::string& pVariableName, const TwType& pVariableType, const void* const pVariable, const std::string& pBehaviourDefinition)
{
	auto it = std::find_if(mBars.begin(), mBars.end(), [&](const std::pair<std::string, TwBar*> bar) { return bar.first == pBarName; });
	TwAddVarRO(it->second, pVariableName.c_str(), pVariableType, const_cast<void*>(pVariable), pBehaviourDefinition.c_str());
}

/// <summary>
/// Deletes a bar from the anttweak GUI
/// </summary>
/// <param name="barName">Name of bar to be deleted</param>
void AntTweakManager::DeleteBar(const std::string& pBarName)
{
	auto it = std::find_if(mBars.begin(), mBars.end(), [&](const std::pair<std::string, TwBar*> bar) { return bar.first == pBarName; });
	TwDeleteBar(it->second);
	mBars.erase(it);
}

/// <summary>
/// Refreshes and draws the anttweak GUI
/// </summary>
void AntTweakManager::Draw()
{
	for (auto& bar : mBars)
	{
		TwRefreshBar(bar.second);
	}
	TwDraw();
}

/// <summary>
/// Deletes all bars and de-allocates all memory assigned to anttweak
/// </summary>
void AntTweakManager::Cleanup() const
{
	TwDeleteAllBars();
	TwTerminate();
}

void AntTweakManager::InititialiseGUI(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, const int pWidth, const int pHeight)
{
	mDevice = pDevice;
	mDeviceWidth = pWidth;
	mDeviceHeight = pHeight;
	mContext = pContext;

	mSpriteBatch = std::make_unique<DirectX::SpriteBatch>(pContext);

	//Microsoft::WRL::ComPtr<ID3D11Texture2D> cat;
	//mResource.As(&cat);
	//CD3D11_TEXTURE2D_DESC catDesc;
	//cat->GetDesc(&catDesc);

}
void AntTweakManager::Render()
{
	mSpriteBatch->Begin();

	for (int i = 0; i < mResourceManager->mSprites.size(); i++)
	{
		auto sprite = mResourceManager->mSprites[i].second;
		mSpriteBatch->Draw(sprite.mTexture.Get(), sprite.mPosition, nullptr, DirectX::Colors::White, sprite.mRotation, sprite.mOrigin, sprite.mScale);
	}

	mSpriteBatch->End();
}
void AntTweakManager::LoadSprite(const wchar_t* pFileName, KodeboldsMath::Vector2 pOrigin, KodeboldsMath::Vector2 pPosition, float pRotation, float pScale)
{
	Sprite sprite;
	sprite.mOrigin = DirectX::XMFLOAT2(pOrigin.X, pOrigin.Y);
	sprite.mPosition = DirectX::XMFLOAT2(pPosition.X, pPosition.Y);
	sprite.mRotation = pRotation;
	sprite.mScale = pScale;

	mResourceManager->mSprites.emplace_back(std::make_pair(pFileName, sprite));

	auto imageTest = DirectX::CreateWICTextureFromFile(mDevice.Get(), mContext.Get(), pFileName, nullptr, mResourceManager->mSprites.back().second.mTexture.GetAddressOf());

	if (imageTest == 0x80070002) // file not found
	{
		int i = 0;
	}

	ID3D11Texture2D* pTextureInterface = 0;
	ID3D11Resource* res;
	mResourceManager->mSprites.back().second.mTexture.Get()->GetResource(&res);
	res->QueryInterface<ID3D11Texture2D>(&pTextureInterface);
	D3D11_TEXTURE2D_DESC desc;
	pTextureInterface->GetDesc(&desc);

	mResourceManager->mSprites.back().second.mWidth = desc.Width;
	mResourceManager->mSprites.back().second.mHeight = desc.Height;
}

void AntTweakManager::LoadSprite(const wchar_t* pFileName, KodeboldsMath::Vector2 pOrigin, SpritePosition pPosition, float pRotation, float pScale)
{
	KodeboldsMath::Vector2 position;

	switch (pPosition)
	{
	case SpritePosition::CENTRE_TOP:
		position.X = mDeviceWidth / 2.0f;
		position.Y = 0;
		break;
	case SpritePosition::CENTRE_MIDDLE:
		position.X = mDeviceWidth / 2.0f;
		position.Y = mDeviceHeight / 2.0f;
		break;
	case SpritePosition::CENTRE_BOTTOM:
		position.X = mDeviceWidth / 2.0f;
		position.Y = mDeviceHeight;
		break;
	}

	LoadSprite(pFileName, pOrigin, position, pRotation, pScale);
}

void AntTweakManager::LoadSprite(const wchar_t* pFileName, SpriteOrigin pOrigin, KodeboldsMath::Vector2 pPosition, float pRotation, float pScale)
{
	Sprite sprite;
	sprite.mOrigin = DirectX::XMFLOAT2(0, 0);
	sprite.mPosition = DirectX::XMFLOAT2(pPosition.X, pPosition.Y);
	sprite.mRotation = pRotation;
	sprite.mScale = pScale;

	mResourceManager->mSprites.emplace_back(std::make_pair(pFileName, sprite));

	auto imageTest = DirectX::CreateWICTextureFromFile(mDevice.Get(), mContext.Get(), pFileName, nullptr, mResourceManager->mSprites.back().second.mTexture.GetAddressOf());

	if (imageTest == 0x80070002) // file not found
	{
		int i = 0;
	}

	ID3D11Texture2D* pTextureInterface = 0;
	ID3D11Resource* res;
	mResourceManager->mSprites.back().second.mTexture.Get()->GetResource(&res);
	res->QueryInterface<ID3D11Texture2D>(&pTextureInterface);
	D3D11_TEXTURE2D_DESC desc;
	pTextureInterface->GetDesc(&desc);

	mResourceManager->mSprites.back().second.mWidth = desc.Width;
	mResourceManager->mSprites.back().second.mHeight = desc.Height;

	KodeboldsMath::Vector2 origin;

	switch (pOrigin)
	{
	case SpriteOrigin::CENTRE:
		origin.X = float(desc.Width / 2);
		origin.Y = float(desc.Height / 2);
		break;
	}

	mResourceManager->mSprites.back().second.mOrigin = DirectX::XMFLOAT2(origin.X, origin.Y);
}

void AntTweakManager::LoadSprite(const wchar_t* pFileName, SpriteOrigin pOrigin, SpritePosition pPosition, float pRotation, float pScale)
{
	Sprite sprite;
	sprite.mOrigin = DirectX::XMFLOAT2(0, 0);
	sprite.mPosition = DirectX::XMFLOAT2(0, 0);
	sprite.mRotation = pRotation;
	sprite.mScale = pScale;

	mResourceManager->mSprites.emplace_back(std::make_pair(pFileName, sprite));

	auto imageTest = DirectX::CreateWICTextureFromFile(mDevice.Get(), mContext.Get(), pFileName, nullptr, mResourceManager->mSprites.back().second.mTexture.GetAddressOf());

	if (imageTest == 0x80070002) // file not found
	{
		int i = 0;
	}

	ID3D11Texture2D* pTextureInterface = 0;
	ID3D11Resource* res;
	mResourceManager->mSprites.back().second.mTexture.Get()->GetResource(&res);
	res->QueryInterface<ID3D11Texture2D>(&pTextureInterface);
	D3D11_TEXTURE2D_DESC desc;
	pTextureInterface->GetDesc(&desc);

	mResourceManager->mSprites.back().second.mWidth = desc.Width;
	mResourceManager->mSprites.back().second.mHeight = desc.Height;

	KodeboldsMath::Vector2 origin;

	switch (pOrigin)
	{
	case SpriteOrigin::CENTRE:
		origin.X = float(desc.Width / 2);
		origin.Y = float(desc.Height / 2);
		break;
	}

	mResourceManager->mSprites.back().second.mOrigin = DirectX::XMFLOAT2(origin.X, origin.Y);

	KodeboldsMath::Vector2 position;

	switch (pPosition)
	{
	case SpritePosition::CENTRE_TOP:
		position.X = mDeviceWidth / 2.0f;
		position.Y = 0;
		break;
	case SpritePosition::CENTRE_MIDDLE:
		position.X = mDeviceWidth / 2.0f;
		position.Y = mDeviceHeight / 2.0f;
		break;
	case SpritePosition::CENTRE_BOTTOM:
		position.X = mDeviceWidth / 2.0f;
		position.Y = mDeviceHeight;
		break;
	}

	mResourceManager->mSprites.back().second.mPosition = DirectX::XMFLOAT2(position.X, position.Y);
}
