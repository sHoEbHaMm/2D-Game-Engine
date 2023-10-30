// MonsterChase2.0.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "MonsterChase2.0.h"
#include "GameObject.h"
#include "ClkTimer.h"
#include "Moveable.h"
#include "Physics.h"
#include "Mutex.h"
#include "ScopeLock.h"
#include "JobSystem.h"
#include "json.hpp"
#include "SmartPtr.h"
#include "Renderer.h"
#include <functional>
#include "Events.h"
#include "HashedString.h"
#include "Helper.h"
#include <stdlib.h>
#include <iostream>

#define MAX_LOADSTRING 100

#include "GLib.h"
#include <DirectXColors.h>
#include <Windows.h>
#include "HashedString.h"
// Global Variables:
/*HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MONSTERCHASE20, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MONSTERCHASE20));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MONSTERCHASE20));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MONSTERCHASE20);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}*/

Moveable* player = nullptr;
static constexpr float FORCE{ 1.0f };
using json = nlohmann::json;



void TestKeyCallback(unsigned int i_VKeyID, bool bWentDown)
{
#ifdef _DEBUG
    const size_t	lenBuffer = 65;
    char			Buffer[lenBuffer];

    sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
    OutputDebugStringA(Buffer);
#endif // __DEBUG

    if (bWentDown) {

        if (i_VKeyID == 0x0044)
        {
            player->AddForce(Point2D(FORCE, 0));
        }
        else if (i_VKeyID == 0x0053)
        {
            player->AddForce(Point2D(0, -FORCE));
        }
        else if (i_VKeyID == 0x0057)
        {
            player->AddForce(Point2D(0, FORCE));
        }
        else if (i_VKeyID == 0x0041)
        {
            player->AddForce(Point2D(-FORCE, 0));
        }
    }

    if (!bWentDown) {

        if (i_VKeyID == 0x0044)
        {
            player->AddForce(Point2D(-FORCE, 0));
        }
        else if (i_VKeyID == 0x0053)
        {
            player->AddForce(Point2D(0, FORCE));
        }
        else if (i_VKeyID == 0x0057)
        {
            player->AddForce(Point2D(0, -FORCE));
        }
        else if (i_VKeyID == 0x0041)
        {
            player->AddForce(Point2D(FORCE, 0));
        }
    }
}

void ProcessFileContents(uint8_t* i_pFileContents, size_t i_sizeFileContents, std::function<void(uint8_t*, size_t)> i_Processor)
{
    if (i_pFileContents)
    {
        if (i_sizeFileContents && !Engine::JobSystem::ShutdownRequested())
            i_Processor(i_pFileContents, i_sizeFileContents);
    }

    delete[] i_pFileContents;

    std::cout << "ProcessFileContents finished processing file.\n";
}

class ProcessFile
{
public:
    ProcessFile(const char* i_pFilename, std::function<void(uint8_t*, size_t)> i_Processor, const Engine::HashedString i_QueueName = Engine::JobSystem::GetDefaultQueue(), Engine::JobSystem::JobStatus* i_pJobStatus = nullptr) :
        m_pFilename(i_pFilename),
        m_Processor(i_Processor),
        m_QueueName(i_QueueName),
        m_pJobStatus(i_pJobStatus)
    {
        assert(m_pFilename);
    }

    void operator() ()
    {
        if (m_pFilename)
        {
            size_t sizeFileContents = 0;
            uint8_t* pFileContents = (uint8_t*)LoadFile(m_pFilename, sizeFileContents);

            if (pFileContents && sizeFileContents)
            {
                if (!Engine::JobSystem::ShutdownRequested())
                {
                    std::cout << "ProcessFile finished loading file.\n";

                    // this works around C++11 issue with capturing member variable by value
                    std::function<void(uint8_t*, size_t)> Processor = m_Processor;

                    Engine::JobSystem::RunJob(
                        m_QueueName,
                        [pFileContents, sizeFileContents, Processor]()
                        {
                            ProcessFileContents(pFileContents, sizeFileContents, Processor);
                        },
                        m_pJobStatus,
                            "ProcessFileContents"
                            );
                }
                else
                {
                    delete[] pFileContents;
                }
            }
        }
    }

private:
    const char* m_pFilename;
    std::function<void(uint8_t*, size_t)>  m_Processor;
    Engine::HashedString m_QueueName;
    Engine::JobSystem::JobStatus* m_pJobStatus;
};

void CreatePlayerObject(uint8_t* i_pFileContents, size_t i_sizeFileContents)
{
    assert(i_pFileContents && i_sizeFileContents);

    i_pFileContents[i_sizeFileContents - 2] = 0;

    json PlayerJSON = json::parse(i_pFileContents);

    if (PlayerJSON.contains("Player")) {

        json position = PlayerJSON["Player"]["Vector"];

        Point2D pos;
        float mass;

        if (position.is_array()) {

            pos.SetX(position[0]);
            pos.SetY(position[1]);
        }

        SmartPtr<GameObject> go = GameObject::CreateNewGO(pos, pos);


        if (PlayerJSON["Player"].contains("Physics")) {

            mass = PlayerJSON["Player"]["Physics"]["Mass"];

            player = Physics::AddPhysicsObject(go, mass);
        }

        if (PlayerJSON["Player"].contains("Renderer")) {

            std::string path = PlayerJSON["Player"]["Renderer"]["Sprite"];
            Renderer::AddRenderable(go, path.c_str());
        }
    }
}

void CreateGameObjects()
{
    using namespace std::placeholders;

    {
        const char* CustomQueueName = "GameObjectLoader";

        Engine::HashedString QueueName = Engine::JobSystem::CreateQueue(CustomQueueName, 1);

        Engine::JobSystem::RunJob(QueueName, std::bind(ProcessFile("Player.json", std::bind(CreatePlayerObject, _1, _2))));

    }
}

int WINAPI wWinMain(_In_ HINSTANCE i_hInstance, _In_opt_ HINSTANCE i_hPrevInstance, _In_ LPWSTR i_lpCmdLine, _In_ int i_nCmdShow)
{
    bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "Test", -1, 800, 600, true);

    Engine::JobSystem::Init();
    CreateGameObjects();

    //GLib::Point2D Playerpos = { 0 , 0 };

    if (bSuccess)
    {
        GLib::SetKeyStateChangeCallback(TestKeyCallback);

        bool bQuit = false;

        //GLib::Sprite* pGoodGuy = CreateSprite("spidu.dds");

        float dt;
        //GLib::Sprite* pBadGuy = CreateSprite("goblin.dds");
        //GLib::Physics playerPhysics;
       // playerPhysics.gameObject->SetPos(Playerpos);

        do
        {
            dt = Timer::CalcLastFrameTime_ms();

            GLib::Service(bQuit);

            if (!bQuit)
            {
                Physics::Update(dt);
                Renderer::Update();
               /* GLib::BeginRendering(DirectX::Colors::Blue);
                GLib::Sprites::BeginRendering();
                Physics::Update(dt);
                GLib::Render(*pGoodGuy, player->GetGameObject()->GetCoordAsPoint2D(), 0.0f, 0.0f);
                // Tell GLib we're done rendering sprites
                GLib::Sprites::EndRendering();
                // IMPORTANT: Tell GLib we're done rendering
                GLib::EndRendering();*/
            }
        } while (bQuit == false);

        Physics::ClearAll();
        Renderer::ClearAll();
        GameObject::ClearAll();

            /*if (pGoodGuy)
            {
                GLib::Release(pGoodGuy);
            }

            Physics::RemovePhysicsObject(player);
            delete player;*/

            GLib::Shutdown();

            Engine::JobSystem::RequestShutdown();

        _CrtDumpMemoryLeaks();
    }
}
