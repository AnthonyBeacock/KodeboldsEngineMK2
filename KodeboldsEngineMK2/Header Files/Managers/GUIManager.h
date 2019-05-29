#pragma once
#include "AntTweakBar.h"
#include <d3d11.h>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <WICTextureLoader.h>
#include <SpriteBatch.h>
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <wrl.h>
#include "ResourceManager.h"
#include "InputManager_DX.h"
#include <CommonStates.h>
#include <SpriteFont.h>
#include "Text.h"
#include "Quad.h"

class GUIManager
{
private:
	std::shared_ptr<ResourceManager> mResourceManager = ResourceManager::Instance();
	std::shared_ptr<InputManager_DX> mInputManager = InputManager_DX::Instance();

	std::vector<std::pair<std::string, TwBar*>> mBars;

	int mDeviceWidth;
	int mDeviceHeight;
	Microsoft::WRL::ComPtr<ID3D11Device> mDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> mContext;

	std::shared_ptr<DirectX::SpriteBatch> mSpriteBatch;
	std::shared_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> mPrimitiveBatch;
	std::shared_ptr<DirectX::BasicEffect> basicEffect;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;

	std::shared_ptr<DirectX::CommonStates> mStates;
	std::vector<std::shared_ptr<DirectX::SpriteFont>> mFonts;
	std::vector<Text> mTexts;

	std::vector<Quad> mQuads;

	//Private constructor for singleton pattern
	GUIManager();

public:
	~GUIManager();

	enum class SpriteOrigin {
		CENTRE,
	};

	enum class SpritePosition {
		CENTRE_TOP,
		CENTRE_MIDDLE,
		CENTRE_BOTTOM
	};
	enum class TextPosition {
		CENTRE_TOP,
		CENTRE_MIDDLE,
		CENTRE_BOTTOM
	};
	enum class TextOrigin {
		CENTRE,
	};
	enum class ButtonOrigin {
		CENTRE,
	};
	enum class ButtonPosition {
		CENTRE_TOP,
		CENTRE_MIDDLE,
		CENTRE_BOTTOM
	};

	//Singleton pattern
	//Deleted copy constructor and assignment operator so no copies of the singleton instance can be made
	GUIManager(const GUIManager& pGUIManager) = delete;
	GUIManager& operator=(GUIManager const&) = delete;

	static std::shared_ptr<GUIManager> Instance();

	//----------- ANT TWEAK BAR GUI -----------\\ 
	void Init(const TwGraphAPI& pGraphicsAPI, void* const pDevice, const int pWidth, const int pHeight) const;
	void AddBar(const std::string& pBarName);
	void AddVariable(const std::string& pBarName, const std::string& pVariableName, const TwType& pVariableType, const void* const pVariable, const std::string& pBehaviourDefinition);
	void DeleteBar(const std::string& pBarName);
	void Draw();
	void Cleanup() const;


	//----------- STANDARD GUI -----------\\ 
	void InititialiseGUI(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, const int pWidth, const int pHeight);
	void Update();
	std::shared_ptr<DirectX::SpriteBatch> GetSpriteBatch() { return mSpriteBatch; }
	std::vector<Text>* GetTextVector() { return &mTexts; }
	std::vector<std::shared_ptr<DirectX::SpriteFont>>* GetFontsVector() { return &mFonts; }
	std::shared_ptr<DirectX::CommonStates> GetCommonStates() { return mStates; }

	// Primitive Shapes
	std::shared_ptr<DirectX::BasicEffect>& GetBasicEffect() { return basicEffect; };
	Microsoft::WRL::ComPtr<ID3D11InputLayout>& GetInputLayout() { return inputLayout; };
	std::shared_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>>& GetPrimitiveBatch() { return mPrimitiveBatch; }
	std::vector<Quad>* GetQuads() { return &mQuads; }

	Quad* CreateQuad(KodeboldsMath::Vector2 pTopLeftPoint, KodeboldsMath::Vector2 pTopRightPoint, KodeboldsMath::Vector2 pBottomRightPoint, KodeboldsMath::Vector2 pBottomLeftPoint,
		KodeboldsMath::Vector4 pTopLeftPointColour, KodeboldsMath::Vector4 pTopLRightPointColour, KodeboldsMath::Vector4 pBottomRightPointColour, KodeboldsMath::Vector4 pBottomLeftPointColour, bool pIsVisible);

	Quad* CreateQuadOverlay(KodeboldsMath::Vector4 pColour, bool pIsVisible);



	// Loads .spritefont files from disk
	void LoadFont(const wchar_t* pFontName);

	// Creates and Draws Button
	Button* CreateButton(const wchar_t* pFileName, const wchar_t* pFontName, const wchar_t* pText, float pRotation, float pButtonScale, float pTextScale,
		ButtonOrigin pOrigin, ButtonPosition pPosition, KodeboldsMath::Vector2 pButtonPadding, KodeboldsMath::Vector2 pTextPadding, KodeboldsMath::Vector4 pTextColour,
		KodeboldsMath::Vector4 pTextColourHover, std::function<void()> pOnClickFunction, bool pIsVisible);

	// Draws Sprite to screen
	void LoadSprite(const wchar_t* pFileName, KodeboldsMath::Vector2 pOrigin, KodeboldsMath::Vector2 pPosition, KodeboldsMath::Vector2 pPadding, float pRotation, float pScale, bool pIsVisible);
	void LoadSprite(const wchar_t* pFileName, KodeboldsMath::Vector2 pOrigin, SpritePosition pPosition, KodeboldsMath::Vector2 pPadding, float pRotation, float pScale, bool pIsVisible);
	void LoadSprite(const wchar_t* pFileName, SpriteOrigin pOrigin, KodeboldsMath::Vector2 pPosition, KodeboldsMath::Vector2 pPadding, float pRotation, float pScale, bool pIsVisible);
	void LoadSprite(const wchar_t* pFileName, SpriteOrigin pOrigin, SpritePosition pPosition, KodeboldsMath::Vector2 pPadding, float pRotation, float pScale, bool pIsVisible);

	// Draws Text to screen
	Text* Write(const wchar_t* pText, KodeboldsMath::Vector2 pOrigin, KodeboldsMath::Vector2 pPosition, KodeboldsMath::Vector2 pPadding, const wchar_t* pFontName, float pRotation, float pScale, KodeboldsMath::Vector4 pColour, bool pIsVisible);
	Text* Write(const wchar_t* pText, KodeboldsMath::Vector2 pOrigin, TextPosition pPosition, KodeboldsMath::Vector2 pPadding, const wchar_t* pFontName, float pRotation, float pScale, KodeboldsMath::Vector4 pColour, bool pIsVisible);
	Text* Write(const wchar_t* pText, TextOrigin pOrigin, KodeboldsMath::Vector2 pPosition, KodeboldsMath::Vector2 pPadding, const wchar_t* pFontName, float pRotation, float pScale, KodeboldsMath::Vector4 pColour, bool pIsVisible);
	Text* Write(const wchar_t* pText, TextOrigin pOrigin, TextPosition pPosition, KodeboldsMath::Vector2 pPadding, const wchar_t* pFontName, float pRotation, float pScale, KodeboldsMath::Vector4 pColour, bool pIsVisible);
};