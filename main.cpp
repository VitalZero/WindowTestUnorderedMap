#include "includes.h"
#include "wndproc.h"
#include "common.h"


int WINAPI WinMain(
  HINSTANCE instance,
  HINSTANCE,
  LPSTR cmd,
  int show)
{
  const wchar_t* CLASS_NAME = L"VZ Window";
  const wchar_t* WINDOW_NAME = L"Gdi32 beginner";

  if(!RegisterWC(CLASS_NAME, WindowProc))
  {
    MessageBox(nullptr, L"Error", L"No se pudo registrar la ventana",
	       MB_ICONINFORMATION);
    return FALSE;
  }
  
  HWND mainWindow = CreateWindowEx(
    WS_EX_CLIENTEDGE,
    CLASS_NAME,
    WINDOW_NAME,
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    nullptr,
    nullptr,
    instance,
    nullptr);

  if(!mainWindow)
  {
    MessageBox(0, L"Error", L"No se pudo crear la ventana principal",
	       MB_ICONINFORMATION);
    return FALSE;
  }

  ShowWindow(mainWindow, show);
  UpdateWindow(mainWindow);

  MSG msg = {0};
  BOOL retMsg;
  while((retMsg = GetMessage(&msg, 0, 0, 0)) != 0)
  {
    if(retMsg == -1)
    {
    }
    else
    {
      if(!IsDialogMessage(mainWindow, &msg))
      {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }
    }
  }
  
  return msg.wParam;
}