#include <unordered_map>
#include <functional>
#include "includes.h"

using MsgFunction = std::function<LRESULT(HWND, UINT, WPARAM, LPARAM)>;
using MessageMap = std::unordered_map<UINT, MsgFunction>;

class MsgHandler
{
public:
  void Register(UINT msg, MsgFunction func);
  LRESULT Handle(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
private:
  MessageMap map;
};