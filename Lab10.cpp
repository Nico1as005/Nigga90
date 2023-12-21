// Lab9.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Lab10.h"
#include <stdio.h>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int arr[256][256];
int w, h, px, py, lvl = 1;

// Отправить объявления функций, включенных в этот модуль кода:
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

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB10, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB10));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB10));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LAB10);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

void LoadLvl() {
    FILE* f;
    char str[100];
    sprintf_s(str, "C:\\Users\\User\\Desktop\\АК\\Temp\\lvl%d.txt", lvl);
    fopen_s(&f, str, "rt");
    fscanf_s(f, "%d%d%d%d", &h, &w, &px, &py);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            fscanf_s(f, "%d", &arr[x][y]);
        }
    }
    fclose(f);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    LoadLvl();

    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

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
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:
        if (wParam == VK_UP) {
            if (arr[px][py - 1] != 1) {
                py--;
            }
            else {
                MessageBoxA(hWnd, "Невозможно пройти в стену", "Ошибка", MB_OK + MB_ICONEXCLAMATION);
            }
            InvalidateRect(hWnd, NULL, false);
        }
        if (wParam == VK_LEFT) {
            if (arr[px - 1][py] != 1) {
                px--;
            }
            else {
                MessageBoxA(hWnd, "Невозможно пройти в стену", "Ошибка", MB_OK + MB_ICONEXCLAMATION);
            }
            InvalidateRect(hWnd, NULL, false);
        }
        if (wParam == VK_DOWN) {
            if (arr[px][py + 1] != 1) {
                py++;
            }
            else {
                MessageBoxA(hWnd, "Невозможно пройти в стену", "Ошибка", MB_OK + MB_ICONEXCLAMATION);
            }
            InvalidateRect(hWnd, NULL, false);
        }
        if (wParam == VK_RIGHT) {
            if (arr[px + 1][py] != 1) {
                px++;
            }
            else {
                MessageBoxA(hWnd, "Невозможно пройти в стену", "Ошибка", MB_OK + MB_ICONEXCLAMATION);
            }
            InvalidateRect(hWnd, NULL, false);
        }
        if (arr[px][py] == 2) {
            char str[100];
            sprintf_s(str, "Вы прошли %d уровень!", lvl);
            if (lvl != 3) {
                lvl++;
                LoadLvl();
            }
            MessageBoxA(hWnd, str, "Победа", MB_OK);
        }
        if (arr[px][py] == 3) {
            char str[100];
            sprintf_s(str, "Вы умерли...");
            InvalidateRect(hWnd, NULL, true);
            lvl = 1;
            LoadLvl();
            MessageBoxA(hWnd, str, "Перезапуск", MB_OK);
        }
        break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
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
        // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
        
        HBRUSH bWall = CreateSolidBrush(RGB(50, 50, 50));
        HBRUSH bEmpty = CreateSolidBrush(RGB(255, 255, 255));
        HBRUSH bPers = CreateSolidBrush(RGB(0, 255, 0));
        HBRUSH bFinish = CreateSolidBrush(RGB(0, 0, 255));
        HBRUSH bTrap = CreateSolidBrush(RGB(255, 0, 0));

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (arr[x][y] == 1) {
                    SelectObject(hdc, bWall);
                    Rectangle(hdc, 30 + 20 * x, 30 + 20 * y, 50 + 20 * x, 50 + 20 * y);
                }
                if (arr[x][y] == 0) {
                    SelectObject(hdc, bEmpty);
                    Rectangle(hdc, 30 + 20 * x, 30 + 20 * y, 50 + 20 * x, 50 + 20 * y);
                }
                if (arr[x][y] == 2) {
                    SelectObject(hdc, bFinish);
                    Rectangle(hdc, 30 + 20 * x, 30 + 20 * y, 50 + 20 * x, 50 + 20 * y);
                }
                if (arr[x][y] == 3) {
                    SelectObject(hdc, bTrap);
                    Rectangle(hdc, 30 + 20 * x, 30 + 20 * y, 50 + 20 * x, 50 + 20 * y);
                }
                if (x == px && y == py) {
                    SelectObject(hdc, bPers);
                    Ellipse(hdc, 30 + 20 * x, 30 + 20 * y, 50 + 20 * x, 50 + 20 * y);
                }
            }
        }
        DeleteObject(bWall);
        DeleteObject(bEmpty);
        DeleteObject(bPers);
        DeleteObject(bFinish);
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

// Обработчик сообщений для окна "О программе".
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
}
