#pragma once
#include "TextureObject.h"
#include "DDSTextureLoader.h"
#include <wrl.h>
#include <d3d11.h>

class RenderSystem_DX;

class TextureObject_DX :
	public TextureObject
{
private:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mTexture;

public:
	TextureObject_DX();
	virtual ~TextureObject_DX();

	HRESULT Create(const RenderSystem_DX* pRenderer, const std::wstring& pFilename) override;
	void Load(const RenderSystem_DX* pRenderer, const int& pSlot) const override;
};