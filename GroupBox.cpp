#include "GroupBox.h"

GroupBox::GroupBox(const std::string& text, int x, int y, int width, int height, HWND parent) {
    hwnd_ = CreateWindowEx(0, L"BUTTON", std::wstring(text.begin(), text.end()).c_str(),
                           WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
                           x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

GroupBox::~GroupBox() {
    DestroyWindow(hwnd_);
}
