#include "GameScene.h"

using namespace KodeboldsMath;
using namespace EntitySpawner;

/// <summary>
///
/// </summary>
void GameScene::Movement()
{
	//Forward movement
	if (mInputManager->KeyDown(KEYS::KEY_W))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration += Vector4(0, 0, 1, 0) * mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration += Vector4(0, 0, 1, 0) * mShipSpeed;
		}
		//If player cam is active, move player cam
		if (mEcsManager->CameraComp(mPlayer)->active)
		{
			mEcsManager->VelocityComp(mPlayer)->acceleration += Vector4(0, 0, 1, 0) * mPlayerSpeed;
			mEcsManager->VelocityComp(mPlayerGun)->acceleration += Vector4(0, 0, -1, 0) * mPlayerSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration += Vector4(0, 0, 1, 0) * mCameraSpeed;
		}
	}
	else if (mInputManager->KeyUp(KEYS::KEY_W))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration -= Vector4(0, 0, 1, 0) * mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration -= Vector4(0, 0, 1, 0) * mShipSpeed;
		}
		//If player cam is active, move player cam
		if (mEcsManager->CameraComp(mPlayer)->active)
		{
			mEcsManager->VelocityComp(mPlayer)->acceleration -= Vector4(0, 0, 1, 0) * mPlayerSpeed;
			mEcsManager->VelocityComp(mPlayerGun)->acceleration -= Vector4(0, 0, -1, 0) * mPlayerSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration -= Vector4(0, 0, 1, 0) * mCameraSpeed;
		}
	}

	//Backwards movement
	if (mInputManager->KeyDown(KEYS::KEY_S))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration += Vector4(0, 0, 1, 0) * -mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration += Vector4(0, 0, 1, 0) * -mShipSpeed;
		}
		//If player cam is active, move player cam
		if (mEcsManager->CameraComp(mPlayer)->active)
		{
			mEcsManager->VelocityComp(mPlayer)->acceleration += Vector4(0, 0, 1, 0) * -mPlayerSpeed;
			mEcsManager->VelocityComp(mPlayerGun)->acceleration += Vector4(0, 0, -1, 0) * -mPlayerSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration += Vector4(0, 0, 1, 0) * -mCameraSpeed;
		}
	}
	else if (mInputManager->KeyUp(KEYS::KEY_S))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration -= Vector4(0, 0, 1, 0) * -mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration -= Vector4(0, 0, 1, 0) * -mShipSpeed;
		}
		//If player cam is active, move player cam
		if (mEcsManager->CameraComp(mPlayer)->active)
		{
			mEcsManager->VelocityComp(mPlayer)->acceleration -= Vector4(0, 0, 1, 0) * -mPlayerSpeed;
			mEcsManager->VelocityComp(mPlayerGun)->acceleration -= Vector4(0, 0, -1, 0) * -mPlayerSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration -= Vector4(0, 0, 1, 0) * -mCameraSpeed;
		}
	}

	//Left movement
	if (mInputManager->KeyDown(KEYS::KEY_A))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration += Vector4(1, 0, 0, 0) * -mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration += Vector4(1, 0, 0, 0) * -mShipSpeed;
		}
		//If player cam is active, move player cam
		if (mEcsManager->CameraComp(mPlayer)->active)
		{
			mEcsManager->VelocityComp(mPlayer)->acceleration += Vector4(1, 0, 0, 0) * -mPlayerSpeed;
			mEcsManager->VelocityComp(mPlayerGun)->acceleration += Vector4(-1, 0, 0, 0) * -mPlayerSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration += Vector4(1, 0, 0, 0) * -mCameraSpeed;
		}
	}
	else if (mInputManager->KeyUp(KEYS::KEY_A))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration -= Vector4(1, 0, 0, 0) * -mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration -= Vector4(1, 0, 0, 0) * -mShipSpeed;
		}
		//If player cam is active, move player cam
		if (mEcsManager->CameraComp(mPlayer)->active)
		{
			mEcsManager->VelocityComp(mPlayer)->acceleration -= Vector4(1, 0, 0, 0) * -mPlayerSpeed;
			mEcsManager->VelocityComp(mPlayerGun)->acceleration -= Vector4(-1, 0, 0, 0) * -mPlayerSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration -= Vector4(1, 0, 0, 0) * -mCameraSpeed;
		}
	}

	//Right movement
	if (mInputManager->KeyDown(KEYS::KEY_D))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration += Vector4(1, 0, 0, 0) * mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration += Vector4(1, 0, 0, 0) * mShipSpeed;
		}
		//If player cam is active, move player cam
		if (mEcsManager->CameraComp(mPlayer)->active)
		{
			mEcsManager->VelocityComp(mPlayer)->acceleration += Vector4(1, 0, 0, 0) * mPlayerSpeed;
			mEcsManager->VelocityComp(mPlayerGun)->acceleration += Vector4(-1, 0, 0, 0) * mPlayerSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration += Vector4(1, 0, 0, 0) * mCameraSpeed;
		}
	}
	else if (mInputManager->KeyUp(KEYS::KEY_D))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration -= Vector4(1, 0, 0, 0) * mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration -= Vector4(1, 0, 0, 0) * mShipSpeed;
		}
		//If player cam is active, move player cam
		if (mEcsManager->CameraComp(mPlayer)->active)
		{
			mEcsManager->VelocityComp(mPlayer)->acceleration -= Vector4(1, 0, 0, 0) * mPlayerSpeed;
			mEcsManager->VelocityComp(mPlayerGun)->acceleration -= Vector4(-1, 0, 0, 0) * mPlayerSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration -= Vector4(1, 0, 0, 0) * mCameraSpeed;
		}
	}

	//Up movement
	if (mInputManager->KeyDown(KEYS::KEY_SPACE))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration += Vector4(0, 1, 0, 0) * mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration += Vector4(0, 1, 0, 0) * mShipSpeed;
		}
		//If player cam is active, move player cam
		if (mEcsManager->CameraComp(mPlayer)->active && mPlayerIsGrounded)
		{
			mEcsManager->VelocityComp(mPlayer)->velocity += Vector4(0, 1, 0, 0) * mPlayerJumpSpeed;
			mEcsManager->VelocityComp(mPlayerGun)->velocity += Vector4(0, 1, 0, 0) * mPlayerJumpSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration += Vector4(0, 1, 0, 0) * mCameraSpeed;
		}
	}
	else if (mInputManager->KeyUp(KEYS::KEY_SPACE))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration -= Vector4(0, 1, 0, 0) * mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration -= Vector4(0, 1, 0, 0) * mShipSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration -= Vector4(0, 1, 0, 0) * mCameraSpeed;
		}
	}

	//Down movement
	if (mInputManager->KeyDown(KEYS::KEY_LEFT_CTRL))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration += Vector4(0, 1, 0, 0) * -mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration += Vector4(0, 1, 0, 0) * -mShipSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration += Vector4(0, 1, 0, 0) * -mCameraSpeed;
		}
	}
	else if (mInputManager->KeyUp(KEYS::KEY_LEFT_CTRL))
	{
		//If ship cam is active, move ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->acceleration -= Vector4(0, 1, 0, 0) * -mShipSpeed;
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration -= Vector4(0, 1, 0, 0) * -mShipSpeed;
		}
		//If free cam is active, move free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->acceleration -= Vector4(0, 1, 0, 0) * -mCameraSpeed;
		}
	}

	//Freeze currently active camera, removing all velocity and acceleration
	if (mInputManager->KeyDown(KEYS::KEY_LEFT_SHIFT))
	{
		//If ship cam is active, freeze ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			mEcsManager->VelocityComp(mPlayerShip)->velocity = Vector4(0, 0, 0, 1);
			mEcsManager->VelocityComp(mPlayerShipCam)->velocity = Vector4(0, 0, 0, 1);
			mEcsManager->VelocityComp(mPlayerShip)->acceleration = Vector4(0, 0, 0, 1);
			mEcsManager->VelocityComp(mPlayerShipCam)->acceleration = Vector4(0, 0, 0, 1);
		}
		//If player cam is active, freeze player cam
		if (mEcsManager->CameraComp(mPlayer)->active)
		{
			mEcsManager->VelocityComp(mPlayer)->velocity = Vector4(0, 0, 0, 1);
			mEcsManager->VelocityComp(mPlayerGun)->velocity = Vector4(0, 0, 0, 1);
			mEcsManager->VelocityComp(mPlayer)->acceleration = Vector4(0, 0, 0, 1);
			mEcsManager->VelocityComp(mPlayerGun)->acceleration = Vector4(0, 0, 0, 1);
		}
		//If free cam is active, freeze free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			mEcsManager->VelocityComp(mCamera)->velocity = Vector4(0, 0, 0, 1);
			mEcsManager->VelocityComp(mCamera)->acceleration = Vector4(0, 0, 0, 1);
		}
	}
}

/// <summary>
///
/// </summary>
void GameScene::Rotation()
{
	float deltaX = mInputManager->MousePos().X;
	float deltaY = mInputManager->MousePos().Y;

	//If mouse moved
	if (deltaX != 0 || deltaY != 0)
	{

		//If ship cam is active, rotate ship
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			//Y rotation
			mEcsManager->TransformComp(mPlayerShip)->transform *= RotationMatrixAxis(DegreesToRadians(deltaX * mRotationSpeed) * mSceneManager->DeltaTime(), Vector4(0, 1, 0, 1));
			RotateAroundPoint(mPlayerShipCam, Vector4(0, 1, 0, 0), Vector4(0, -40, 75, 0), deltaX * mRotationSpeed);

			//X rotation
			mEcsManager->TransformComp(mPlayerShip)->transform *= RotationMatrixAxis(DegreesToRadians(deltaY * mRotationSpeed) * mSceneManager->DeltaTime(), Vector4(1, 0, 0, 1));
			RotateAroundPoint(mPlayerShipCam, Vector4(1, 0, 0, 0), Vector4(0, -40, 75, 0), deltaY * mRotationSpeed);
		}
		//If player cam is active, rotate player
		if (mEcsManager->CameraComp(mPlayer)->active)
		{
			//Y rotation
			mEcsManager->TransformComp(mPlayer)->transform *= RotationMatrixAxis(DegreesToRadians(deltaX * mRotationSpeed) * mSceneManager->DeltaTime(), Vector4(0, 1, 0, 1));
			RotateAroundPoint(mPlayerGun, Vector4(0, 1, 0, 0), Vector4(1, -1, 2.0f, 0), deltaX * mRotationSpeed);

			//X rotation
			mEcsManager->TransformComp(mPlayer)->transform *= RotationMatrixAxis(DegreesToRadians(deltaY * mRotationSpeed) * mSceneManager->DeltaTime(), Vector4(1, 0, 0, 1));
			RotateAroundPoint(mPlayerGun, Vector4(1, 0, 0, 0), Vector4(1, -1, 2.0f, 0), deltaY * mRotationSpeed);
		}
		//If free cam is active, rotate free cam
		if (mEcsManager->CameraComp(mCamera)->active)
		{
			//Y rotation
			mEcsManager->TransformComp(mCamera)->transform *= RotationMatrixAxis(DegreesToRadians(deltaX * mRotationSpeed) * mSceneManager->DeltaTime(), Vector4(0, 1, 0, 1));

			//X rotation
			mEcsManager->TransformComp(mCamera)->transform *= RotationMatrixAxis(DegreesToRadians(deltaY * mRotationSpeed) * mSceneManager->DeltaTime(), Vector4(1, 0, 0, 1));
		}
	}
}

/// <summary>
///
/// </summary>
void GameScene::Shooting()
{
	//Fire on left click
	if (mInputManager->KeyDown(KEYS::MOUSE_BUTTON_LEFT))
	{
		//If ship cam is active, fire ship lasers
		if (mEcsManager->CameraComp(mPlayerShipCam)->active)
		{
			Vector4 leftLaser = mEcsManager->TransformComp(mPlayerShip)->translation + ((mEcsManager->TransformComp(mPlayerShip)->right * -23) + (mEcsManager->TransformComp(mPlayerShip)->up * 5));
			SpawnLaser(leftLaser, Vector4(1, 1, 1, 1), Vector4(0, 0, 0, 1), Vector4(1, 0, 0, 1), mEcsManager->TransformComp(mPlayerShip)->forward * 40, 40,
				1, CustomCollisionMask::SHIP_LASER, CustomCollisionMask::SHIP_LASER | CustomCollisionMask::SHIP, 100, L"laser.wav");

			Vector4 rightLaser = mEcsManager->TransformComp(mPlayerShip)->translation + ((mEcsManager->TransformComp(mPlayerShip)->right * 23) + (mEcsManager->TransformComp(mPlayerShip)->up * 5));
			SpawnLaser(rightLaser, Vector4(1, 1, 1, 1), Vector4(0, 0, 0, 1), Vector4(1, 0, 0, 1), mEcsManager->TransformComp(mPlayerShip)->forward * 40, 40,
				1, CustomCollisionMask::SHIP_LASER, CustomCollisionMask::SHIP_LASER | CustomCollisionMask::SHIP, 100, L"laser.wav");
		}

		//If player cam is active, fire gun
		if (mEcsManager->CameraComp(mPlayer)->active)
		{
			Vector4 gunBarrel = mEcsManager->TransformComp(mPlayerGun)->translation + (mEcsManager->TransformComp(mPlayerGun)->forward * -2);
			SpawnLaser(gunBarrel, Vector4(1, 1, 1, 1), Vector4(0, 0, 0, 1), Vector4(1, 0, 0, 1), mEcsManager->TransformComp(mPlayerGun)->forward * -30, 40,
				1, CustomCollisionMask::GUN_LASER, CustomCollisionMask::GUN_LASER | CustomCollisionMask::PLAYER, 50, L"laser.wav");
		}
	}
}

/// <summary>
///
/// </summary>
/// <param name="pAxis"></param>
/// <param name="pPoint"></param>
/// <param name="pAngle"></param>
void GameScene::RotateAroundPoint(const int pEntity, const KodeboldsMath::Vector4 & pAxis, const KodeboldsMath::Vector4 & pPoint, const float& pAngle)
{
	const float angleInRadians = DegreesToRadians(pAngle);

	auto translateTo = TranslationMatrix(pPoint);
	auto rotation = RotationMatrixAxis(angleInRadians * mSceneManager->DeltaTime(), pAxis);
	auto translateBack = TranslationMatrix(pPoint * -1);

	mEcsManager->TransformComp(pEntity)->transform *= translateTo * rotation * translateBack;
}

void GameScene::OnClick_MainMenuButton()
{
	mSceneManager->LoadScene<MenuScene>();
}

void GameScene::OnClick_ResumeGameButton()
{
}

/// <summary>
/// Default constructor
/// </summary>
GameScene::GameScene()
{
}

/// <summary>
/// Default destructor
/// </summary>
GameScene::~GameScene()
{
}

/// <summary>
/// Update loop for the scene
/// </summary>
void GameScene::Update()
{
	if (mGameState == GAME_STATE::PLAYING)
	{
		Movement();
		Rotation();
		Shooting();

		//Switch between cameras
		//Ship

		if (mInputManager->KeyDown(KEYS::KEY_F1))
		{
			mEcsManager->CameraComp(mPlayerShipCam)->active = true;
			mEcsManager->CameraComp(mPlayer)->active = false;
			mEcsManager->CameraComp(mCamera)->active = false;
		}
		//Player
		if (mInputManager->KeyDown(KEYS::KEY_F2))
		{
			mEcsManager->CameraComp(mPlayerShipCam)->active = false;
			mEcsManager->CameraComp(mPlayer)->active = true;
			mEcsManager->CameraComp(mCamera)->active = false;
		}
		//Free cam
		if (mInputManager->KeyDown(KEYS::KEY_F3))
		{
			mEcsManager->CameraComp(mPlayerShipCam)->active = false;
			mEcsManager->CameraComp(mPlayer)->active = false;
			mEcsManager->CameraComp(mCamera)->active = true;
		}

		//If the player doesn't have a gravity component
		if (!mEcsManager->GravityComp(mPlayer))
		{
			//Check if the player is colliding with something, else add gravity
			if (mEcsManager->CollisionComp(mPlayer))
			{
				//If it's not the floor, player is not grounded, add gravity
				if (!(mEcsManager->CollisionComp(mPlayer)->collidedEntityCollisionMask == CustomCollisionMask::FLOOR))
				{
					mEcsManager->AddGravityComp(Gravity{}, mPlayer);
					mEcsManager->AddGravityComp(Gravity{}, mPlayerGun);
					mPlayerIsGrounded = false;
				}
				else
				{
					mPlayerIsGrounded = true;
				}
			}
			else
			{
				mEcsManager->AddGravityComp(Gravity{}, mPlayer);
				mEcsManager->AddGravityComp(Gravity{}, mPlayerGun);
				mPlayerIsGrounded = false;
			}
		}

		// Turn On Pause Menu
		if (mInputManager->KeyDown(KEYS::KEY_ESC))
		{
			OnPause();
		}
	}
	else { // the game is now paused


		// Turn off Pause Menu
		if (mInputManager->KeyDown(KEYS::KEY_ESC))
		{
			OnUnPause();
		}
	}
}

/// <summary>
/// Scene setup on load
/// </summary>
void GameScene::OnLoad()
{
	// Clears GUI from previous scene
	resourceManager->mSprites.clear();
	resourceManager->mButtons.clear();
	mGUIManager->GetQuads()->clear();
	mGUIManager->GetTextVector()->clear();

	// allows the user to use the mouse again as normal
	mInputManager->CenterCursor(true);

	//Spawn player ship and attached camera
	mPlayerShipStartPos = Vector4(0, 0, -50, 1);
	mPlayerShip = SpawnShip(mPlayerShipStartPos, Vector4(1, 1, 1, 1), Vector4(0, 0, 0, 0), 40, 50, CustomCollisionMask::SHIP,
		CustomCollisionMask::SHIP | CustomCollisionMask::SHIP_LASER | CustomCollisionMask::PLAYER, L"stones.dds", L"stones_NM_height.dds");
	mPlayerShipCam = SpawnCamera(mPlayerShipStartPos + Vector4(0, 40, -75, 1), Vector4(1, 1, 1, 1), Vector4(0, 0, 0, 0), 60, 1, 10000, 40);
	mEcsManager->CameraComp(mPlayerShipCam)->active = true;

	//Spawn player camera and attached laser gun model
	mPlayerStartPos = Vector4(0, 50, -100, 1);
	mPlayer = SpawnPlayer(mPlayerStartPos, Vector4(1, 1, 1, 1), Vector4(0, 0, 0, 0), 60, 1, 10000, 10, mPlayerStartPos.XYZ() - Vector3(1, 4, 1), mPlayerStartPos.XYZ() + Vector3(1, 2, 1),
		CustomCollisionMask::PLAYER, CustomCollisionMask::PLAYER | CustomCollisionMask::GUN_LASER | CustomCollisionMask::SHIP);
	mPlayerGun = SpawnLaserGun(mPlayerStartPos + Vector4(1, -1, 2.0f, 0), Vector4(1, 1, 1, 1), Vector4(0, 3.14f, 0, 1), L"laser_gun_diffuse.dds", L"laser_gun_normal.dds", 10);


	//Spawn free cam
	mCamera = SpawnCamera(Vector4(5, 2, -100, 1), Vector4(1, 1, 1, 1), Vector4(0, 0, 0, 0), 60, 1, 10000, 50);

	//Set acceleration speeds
	mPlayerSpeed = 20.0f;
	mPlayerJumpSpeed = 20.0f;
	mShipSpeed = 20.0f;
	mCameraSpeed = 20.0f;
	mRotationSpeed = 10.0f;


	//Spawn platform
	int entity = mEcsManager->CreateEntity();
	Geometry geom{ L"cube.obj" };
	mEcsManager->AddGeometryComp(geom, entity);
	Shader shaderm{ L"defaultShader.fx" , BlendState::NOBLEND, CullState::BACK, DepthState::LESSEQUAL };
	mEcsManager->AddShaderComp(shaderm, entity);
	Texture texturem{};
	texturem.diffuse = L"stones.dds";
	texturem.normal = L"stones_NM_height.dds";
	mEcsManager->AddTextureComp(texturem, entity);
	Transform transCm{};
	transCm.scale = Vector4(100, 2, 100, 1);
	transCm.translation = Vector4(0, -2, -100, 1);
	mEcsManager->AddTransformComp(transCm, entity);
	BoxCollider floorBox{ transCm.translation.XYZ() - Vector3(100, 2, 100), transCm.translation.XYZ() + Vector3(100, 2, 100), CustomCollisionMask::FLOOR, CustomCollisionMask::FLOOR };
	mEcsManager->AddBoxColliderComp(floorBox, entity);

	{
		//Sun
		int entity = mEcsManager->CreateEntity();

		Geometry geom{ L"sphere.obj" };
		mEcsManager->AddGeometryComp(geom, entity);
		Shader shaderm{ L"sunShader.fx" , BlendState::NOBLEND, CullState::BACK, DepthState::LESSEQUAL };

		mEcsManager->AddShaderComp(shaderm, entity);
		Transform transCm{};
		transCm.translation = Vector4(0, 0, 1250, 1);

		transCm.scale = Vector4(500, 500, 500, 1);
		mEcsManager->AddTransformComp(transCm, entity);
	}

	{
		//Skybox
		int entity = mEcsManager->CreateEntity();

		Geometry geom{ L"cube.obj" };
		mEcsManager->AddGeometryComp(geom, entity);
		Shader shaderm{ L"skyboxShader.fx" , BlendState::NOBLEND, CullState::FRONT, DepthState::LESSEQUAL };
		mEcsManager->AddShaderComp(shaderm, entity);
		Transform transCm{};
		transCm.scale = Vector4(1, 1, 1, 1);
		transCm.translation = Vector4(0, 0, 0, 1);
		mEcsManager->AddTransformComp(transCm, entity);
	}

	//Spawn some asteroids
	for (int i = -20; i < 20; i++)
	{
		for (int j = -5; j < 5; j++)
		{
			for (int k = 10; k > 2; k--)
			{
				SpawnAsteroid(Vector4(40 * i, 60 * j, 40 * k, 1), Vector4(1, 1, 1, 1), Vector4(0, 0, 0, 1), 10, 0, L"asteroid_diffuse.dds", L"asteroid_normal.dds");
			}
		}
	}

	{
		int particleEntity = mEcsManager->CreateEntity();
		Geometry geom{ L"quad100.obj" };
		mEcsManager->AddGeometryComp(geom, particleEntity);
		Shader shaderm{ L"thrusterShader.fx" , BlendState::ALPHABLEND, CullState::NONE, DepthState::NONE };
		mEcsManager->AddShaderComp(shaderm, particleEntity);
		Texture texturem{};
		texturem.diffuse = L"";
		texturem.normal = L"";
		mEcsManager->AddTextureComp(texturem, particleEntity);

		Transform transCm{};
		transCm.scale = Vector4(10, 10, 10, 10);
		transCm.translation = Vector4(0, 0, 0, 1);

		mEcsManager->AddTransformComp(transCm, particleEntity);
	}

	{
		int screenspaceQuad = mEcsManager->CreateEntity();
		Geometry geom{ L"cube.obj" };
		mEcsManager->AddGeometryComp(geom, screenspaceQuad);
		Shader shaderm{ L"distortionShader.fx" , BlendState::ALPHABLEND, CullState::NONE, DepthState::NONE };
		//mEcsManager->AddShaderComp(shaderm, screenspaceQuad);
		Texture texturem{};
		texturem.diffuse = L"stones.DDS";
		texturem.normal = L"distortionTest.dds";
		mEcsManager->AddTextureComp(texturem, screenspaceQuad);

		Transform transCm{};
		transCm.scale = Vector4(10, 10, 10, 10);
		transCm.translation = Vector4(0, 0, 0, 1);

		mEcsManager->AddTransformComp(transCm, screenspaceQuad);
	}

	const int dLight = mEcsManager->CreateEntity();
	DirectionalLight dl{ Vector4(0, 0, 1, 1), Vector4(1.0f, 0.8f, 0.7f, 1) };
	mEcsManager->AddDirectionalLightComp(dl, dLight);

	const int pLight = mEcsManager->CreateEntity();
	PointLight pl{ Vector4(1.0f,1.0f,1.0f,1), 50 };
	mEcsManager->AddPointLightComp(pl, pLight);
	Transform t;
	t.translation = Vector4(5, 20, -100, 1);
	t.scale = Vector4(1, 1, 1, 1);
	mEcsManager->AddTransformComp(t, pLight);

	//AntTweak
	mGUIManager->AddBar("Testing");
	TwDefine(" Testing size='300 320' valueswidth=200 ");
	mGUIManager->AddVariable("Testing", "Velocity", TW_TYPE_DIR3F, &mEcsManager->VelocityComp(mPlayer)->velocity, "");
	mGUIManager->AddVariable("Testing", "Acceleration", TW_TYPE_DIR3F, &mEcsManager->VelocityComp(mPlayer)->acceleration, "");
	mGUIManager->AddVariable("Testing", "Max Speed", TW_TYPE_FLOAT, &mEcsManager->VelocityComp(mPlayer)->maxSpeed, "");


	//------------ GUI ------------\\
	// Crosshair
	mCrosshair = mGUIManager->LoadSprite(L"crosshair.png", GUIManager::SpriteOrigin::CENTRE, GUIManager::SpritePosition::CENTRE_MIDDLE, Vector2(0, 0), 0, 0.045f, true);

	// Lives
	mLivesText = mGUIManager->Write(L"LIVES: ", GUIManager::TextOrigin::CENTRE, GUIManager::TextPosition::LEFT_BOTTOM, Vector2(120, -150), L"AlienEncounters.spritefont",
		0.0f, 0.75f, Vector4(1.0f, 0.0f, 0.0f, 1.0f), true);

	for (int i = 0; i < mLives; i++)
	{
		Sprite* life = mGUIManager->LoadSprite(L"heart.png", GUIManager::SpriteOrigin::CENTRE, Vector2(mLivesText->mPosition.x, mLivesText->mPosition.y), Vector2(150 + (i * 75), -10), 0, 0.25f, true);
		mLivesVector.emplace_back(life);
	}

	// Bullets
	mBulletText = mGUIManager->Write(L"BULLETS: ", GUIManager::TextOrigin::CENTRE, GUIManager::TextPosition::LEFT_BOTTOM, Vector2(170, -50), L"AlienEncounters.spritefont",
		0.0f, 0.75f, Vector4(1.0f, 0.0f, 0.0f, 1.0f), true);

	for (int i = 0; i < mBullets; i++)
	{
		Sprite* bullet = mGUIManager->LoadSprite(L"bullet.png", GUIManager::SpriteOrigin::CENTRE, Vector2(mBulletText->mPosition.x, mBulletText->mPosition.y), Vector2(190 + (i * 75), -10), 0, 0.1f, true);
		mBulletVector.emplace_back(bullet);
	}

	// SCORE
	mScoreLabelText = mGUIManager->Write(L"SCORE: ", GUIManager::TextOrigin::CENTRE, GUIManager::TextPosition::LEFT_BOTTOM, Vector2(130, -250), L"AlienEncounters.spritefont",
		0.0f, 0.75f, Vector4(1.0f, 0.0f, 0.0f, 1.0f), true);
	mScoreText = mGUIManager->Write(L"0", GUIManager::TextOrigin::CENTRE, Vector2(mScoreLabelText->mPosition.x, mScoreLabelText->mPosition.y), Vector2(150, 0), L"AlienEncounters.spritefont",
		0.0f, 0.75f, Vector4(1.0f, 0.0f, 0.0f, 1.0f), true);



	// Loading of Pause Menu (initallity hidden)

	// creates a panel that covers the screen when game is paused
	mPausedOverlay = mGUIManager->CreateQuadOverlay(Vector4(0.1f, 0.1f, 0.1f, 1.0f), false);

	//mPausedOverlay = mGUIManager->CreateQuad(
	//	Vector2(0, 0), Vector2(100, 0), Vector2(100, 1200), Vector2(0, 1200),
	//	Vector4(0.5f, 0.5f, 0.5f, 1.0f), Vector4(0.5f, 0.5f, 0.5f, 1.0f), Vector4(0.5f, 0.5f, 0.5f, 1.0f), Vector4(0.5f, 0.5f, 0.5f, 1.0f), false);

	mPausedText = mGUIManager->Write(L"PAUSED", GUIManager::TextOrigin::CENTRE, GUIManager::TextPosition::CENTRE_TOP, Vector2(0, 250), L"AlienEncounters.spritefont", 0.0f, 1.5f, Vector4(1.0f, 0.0f, 0.0f, 1.0f), false);

	// Creates a button that allows the user to resume the game
	mResumeGameButton = mGUIManager->CreateButton(L"button.png", L"AlienEncounters.spritefont", L"RESUME", 0, 0.35f, 0.65f,
		GUIManager::ButtonOrigin::CENTRE, GUIManager::ButtonPosition::CENTRE_MIDDLE, Vector2(0, 0),
		Vector2(0, 10), Vector4(0.0f, 0.0f, 0.0f, 1.0f), Vector4(1.0f, 1.0f, 0.0f, 1.0f), std::bind(&GameScene::OnClick_ResumeGameButton, this), false);

	// Creates a button that allows the user to exit back to the main menu
	mPausedExitButton = mGUIManager->CreateButton(L"button.png", L"AlienEncounters.spritefont", L"MAIN MENU", 0, 0.35f, 0.65f,
		GUIManager::ButtonOrigin::CENTRE, GUIManager::ButtonPosition::CENTRE_MIDDLE, Vector2(0, 100),
		Vector2(0, 10), Vector4(0.0f, 0.0f, 0.0f, 1.0f), Vector4(1.0f, 1.0f, 0.0f, 1.0f), std::bind(&GameScene::OnClick_MainMenuButton, this), false);


	mGameState = GAME_STATE::PLAYING;
}

/// <summary>
/// Clear up scene resources
/// </summary>
void GameScene::OnUnload()
{
	// Clears GUI from previous scene
	resourceManager->mSprites.clear();
	resourceManager->mButtons.clear();
	mGUIManager->GetQuads()->clear();
	mGUIManager->GetTextVector()->clear();

	mEcsManager->DestroyEntities();
}

void GameScene::OnPause()
{
	mGameState = GAME_STATE::PAUSED;
	//exit(0);

	// allows the user to use the mouse again as normal
	mInputManager->CenterCursor(false);

	// TODO: STOP EVERYTHING IN THE GAME
	//mSceneManager->Pause(true);

	// make all of the pause menu attributes (GUI) visible
	//mPausedOverlay->mIsVisible = true;
	mPausedText->mIsVisible = true;
	mPausedExitButton->SetVisibility(true);
	mResumeGameButton->SetVisibility(true);

}

void GameScene::OnUnPause()
{
	mGameState = GAME_STATE::PLAYING;

	// TODO: START EVERYTHING AGAIN
	//mSceneManager->Pause(false);

	//exit(0);
	mPausedOverlay->mIsVisible = false;
	mPausedText->mIsVisible = false;
	mPausedExitButton->SetVisibility(false);
	mResumeGameButton->SetVisibility(false);

	// allows the user to use the centered mouse
	mInputManager->CenterCursor(true);
}
