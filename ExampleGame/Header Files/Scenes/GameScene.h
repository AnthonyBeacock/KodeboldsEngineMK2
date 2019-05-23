#pragma once
#include "Scene.h"
#include <memory>
#include "NetworkManager.h"
#include "InputManager_DX.h"
#include "InputManager_GL.h"
#include "SceneManager.h"
#include "EntitySpawner.h"
#include "GUIManager.h"

class GameScene : public Scene
{
private:
	//Managers
	std::shared_ptr<ECSManager> mEcsManager = ECSManager::Instance();
	std::shared_ptr<NetworkManager> mNetworkManager = NetworkManager::Instance();
#ifdef  DIRECTX
	std::shared_ptr<InputManager_DX> mInputManager = InputManager_DX::Instance();
#elif OPENGL
	std::shared_ptr<InputManager_GL> mInputManager = InputManager_GL::Instance();
#endif
	std::shared_ptr<SceneManager> mSceneManager = SceneManager::Instance();
	std::shared_ptr<GUIManager> mGUIManager = GUIManager::Instance();

	int mPlayer;
	int mCamera;
	float mCameraSpeed;
<<<<<<< HEAD
	float mPlayerSpeed;
=======

<<<<<<< HEAD
<<<<<<< HEAD
	KodeboldsMath::Vector4 mPlayerShipStartPos;
	KodeboldsMath::Vector4 mPlayerStartPos;
	KodeboldsMath::Vector4 mFreeCamStartPos;

	void Movement();
	void Rotation();
	void Shooting();
>>>>>>> parent of 0f257ec... Merge branch 'master' into master

=======
>>>>>>> parent of 96b83d6... Added sound - still refactoring
=======
>>>>>>> parent of 96b83d6... Added sound - still refactoring
public:
	//Structors
	GameScene();
	~GameScene();

	void Update() override;
	void OnLoad() override;
	void OnUnload() override;
};
