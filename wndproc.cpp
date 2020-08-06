#include "wndproc.h"
#include "MsgHandler.h"

static MsgHandler handler;

LRESULT OnCreate(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
LRESULT OnDestroy(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);

LRESULT CALLBACK WindowProc(
  HWND   hwnd,
  UINT   msg,
  WPARAM wparam,
  LPARAM lparam)
{
  handler.Register(WM_CREATE, OnCreate);
  handler.Register(WM_DESTROY, OnDestroy);

  return handler.Handle(hwnd, msg, wparam, lparam);
}

LRESULT OnCreate(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
  MessageBox(wnd, L"This is on create!", L"Through an unordered_map!", 0);

  return 1;
}

LRESULT OnDestroy(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
  PostQuitMessage(0);
  return 0;
}