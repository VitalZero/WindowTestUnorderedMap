#include "MsgHandler.h"

void MsgHandler::Register(UINT msg, MsgFunction func)
{
  if(map.find(msg) == map.end())
  {
    map[msg] = func;
  }
}

LRESULT MsgHandler::Handle(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
  auto itr = map.find(msg);
  if(itr != map.end())
  {
    return itr->second(wnd, msg, wparam, lparam);
  }

  return DefWindowProc(wnd, msg, wparam, lparam);
}