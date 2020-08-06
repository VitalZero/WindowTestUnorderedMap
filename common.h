#include "includes.h"

// Definitinons
ATOM RegisterWC(const wchar_t* className, WNDPROC WindowProc);
BOOL CALLBACK ChangeChildrenFontProc(HWND hwnd, LPARAM lparam);
void DrawDivider(HDC hdc, int x, int y, int width);


// Declarations
ATOM RegisterWC(const wchar_t* className, WNDPROC WindowProc)
{
  WNDCLASS wc = {0};

  wc.lpfnWndProc = WindowProc;
  wc.hInstance = GetModuleHandle(nullptr);
  wc.hIcon = LoadIcon(wc.hInstance, IDI_APPLICATION);
  wc.hCursor = LoadCursor(wc.hInstance, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);//(HBRUSH)GetStockObject(BLACK_BRUSH);
  wc.lpszClassName = className;

  return RegisterClass(&wc);
}

void DrawDivider(HDC hdc, int x, int y, int width)
{
  RECT rc = {0};
  rc.left = x;
  rc.right = x + width;
  rc.top = y;
  rc.bottom = y + 2;
  DrawEdge(hdc, &rc, BDR_SUNKENINNER, BF_TOP | BF_BOTTOM);
}

BOOL CALLBACK ChangeChildrenFontProc(HWND hwnd, LPARAM lparam)
{
  SendMessage(hwnd, WM_SETFONT, (WPARAM)lparam, (LPARAM)TRUE);
  return TRUE;
}