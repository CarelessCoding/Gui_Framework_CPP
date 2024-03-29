#include "Label.h"

Label::Label(const std::string& text, int x, int y, int width, int height, HWND parent)
    : text_(text) {
    hwnd_ = CreateWindowEx(0, L"STATIC", std::wstring(text.begin(), text.end()).c_str(),
                           WS_VISIBLE | WS_CHILD | SS_CENTER,
                           x, y, width, height,
                           parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

Label::~Label() {
    DestroyWindow(hwnd_);
}

void Label::setText(const std::string& text) {
    text_ = text;
    SetWindowText(hwnd_, std::wstring(text.begin(), text.end()).c_str());
}
