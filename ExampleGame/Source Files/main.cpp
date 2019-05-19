#include "GameScene.h"
#include <windows.h>
#include <memory>
#include "Systems.h"
#include "CustomComponents.h"

#pragma comment(lib, "KodeboldsEngineMK2.lib")

using namespace KodeboldsMath;

HINSTANCE hInst = nullptr;
HWND hWnd = nullptr;

HRESULT InitWindow(HINSTANCE pHInstance, int pNCmdShow);

/// <summary>
/// Entry point to the program. Initializes everything and goes into a message processing loop.
/// </summary>
/// <param name="pHInstance"></param>
/// <param name="pHPrevInstance"></param>
/// <param name="pLpCmdLine"></param>
/// <param name="pNCmdShow"></param>
/// <returns></returns>
int WINAPI wWinMain(_In_ const HINSTANCE pHInstance, _In_opt_ const HINSTANCE pHPrevInstance, _In_ const LPWSTR pLpCmdLine, _In_ const int pNCmdShow)
{
	UNREFERENCED_PARAMETER(pHPrevInstance);
	UNREFERENCED_PARAMETER(pLpCmdLine);

	if (FAILED(InitWindow(pHInstance, pNCmdShow)))
	{
		return 0;
	}

	//Managers
	std::shared_ptr<ECSManager> ecsManager = ECSManager::Instance();
	std::shared_ptr<SceneManager> sceneManager = SceneManager::Instance();
	std::shared_ptr<ThreadManager> threadManager = ThreadManager::Instance();
	std::shared_ptr<NetworkManager> networkManager = NetworkManager::Instance();
	std::shared_ptr<AntTweakManager> anttweakManager = AntTweakManager::Instance();

	//Initialise winsock
	networkManager->InitWinSock(9171);

	//Get window height and width for scene manager
	RECT rc;
	GetClientRect(hWnd, &rc);
	float width = static_cast<float>(rc.right - rc.left);
	float height = static_cast<float>(rc.bottom - rc.top);
	sceneManager->SetWindowWidthHeight(width, height);

	//Render systems
#ifdef DIRECTX
	ecsManager->AddRenderSystem(std::make_shared<RenderSystem_DX>(hWnd));
#elif OPENGL
	ecsManager->AddRenderSystem(std::make_shared<RenderSystem_DX>(hWnd));
#endif

	ecsManager->AddUpdateSystem(std::make_shared<MovementSystem>());
	ecsManager->AddUpdateSystem(std::make_shared<CollisionCheckSystem>(500, 5));

	//Create camera
	int entityID = ecsManager->CreateEntity();
	Camera cam{Vector4(0, 0, 1, 1), Vector4(0, 1, 0, 1), 60, 1, 200};
	ecsManager->AddCameraComp(cam, entityID);
	Transform trans{};
	trans.translation = Vector4(0, 0, -100, 1);
	ecsManager->AddTransformComp(trans, entityID);

	//Create light
	entityID = ecsManager->CreateEntity();
	Light light{Vector4(1, 1, 1, 1)};
	ecsManager->AddLightComp(light, entityID);
	Transform transL{};
	transL.translation = Vector4(0, -20, -10, 1);
	ecsManager->AddTransformComp(transL, entityID);


	//Testing custom components
	ecsManager->CreateCustomComponent<CustomComp1>(CustomComponentType::CUSTOM_COMPONENT_1);
	ecsManager->CreateCustomComponent<CustomComp2>(CustomComponentType::CUSTOM_COMPONENT_2);

	CustomComp1 CC1{};
	if (!ecsManager->AddCustomComponent<CustomComp1>(CC1, entityID))
	{
		OutputDebugString(L"REEEEEE");
	}

	CustomComp2 CC2{};
	if (!ecsManager->AddCustomComponent<CustomComp2>(CC2, entityID))
	{
		OutputDebugString(L"REEEEEE");
	}

	CustomComp1* CC1Ptr = ecsManager->GetCustomComponent<CustomComp1>(entityID);
	CustomComp2* CC2Ptr = ecsManager->GetCustomComponent<CustomComp2>(entityID);

	if (!ecsManager->RemoveCustomComponent<CustomComp1>(entityID))
	{
		OutputDebugString(L"REEEEEE");
	}

	if (!ecsManager->RemoveCustomComponent<CustomComp2>(entityID))
	{
		OutputDebugString(L"REEEEEE");
	}

	//Scenes
	sceneManager->LoadScene<GameScene>();

	//Main message loop
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//Update scenes
			sceneManager->Update();
		}
	}

	return static_cast<int>(msg.wParam);
}

/// <summary>
/// Register class and create window
/// </summary>
/// <param name="pHInstance"></param>
/// <param name="pNCmdShow"></param>
/// <returns></returns>
HRESULT InitWindow(const HINSTANCE pHInstance, const int pNCmdShow)
{
	//Register class
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
#ifdef  DIRECTX
	wcex.lpfnWndProc = InputManager_DX::WndProc;
#elif OPENGL
	wcex.lpfnWndProc = InputManager_GL::WndProc;
#endif
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = pHInstance;
	wcex.hIcon = LoadIcon(pHInstance, nullptr);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = nullptr;
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"Kodebolds Space Game";
	wcex.hIconSm = LoadIcon(wcex.hInstance, nullptr);
	if (!RegisterClassEx(&wcex))
	{
		return static_cast<HRESULT>(0x80004005L);
	}

	//Create window
	hInst = pHInstance;
	RECT rc = { 0, 0, 1920, 1080 };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	hWnd = CreateWindow(L"Kodebolds Space Game", L"Kodebolds Space Game",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, pHInstance,
		nullptr);
	if (!hWnd)
	{
		return static_cast<HRESULT>(0x80004005L);
	}

	ShowWindow(hWnd, pNCmdShow);

	return static_cast<HRESULT>(0L);
}