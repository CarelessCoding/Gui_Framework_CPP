#include "Button.h"

Button::Button(const std::string& text, int x, int y, int width, int height, HWND parent, std::function<void()> onClick)
    : onClick_(onClick) {
    hwnd_ = CreateWindowEx(0, L"BUTTON", std::wstring(text.begin(), text.end()).c_str(),
                           WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                           x, y, width, height,
                           parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

Button::~Button() {
    DestroyWindow(hwnd_);
}
HWND Button::getHandle() const {
    return hwnd_;
}

std::function<void()> Button::getOnClick() const {
    return onClick_;
}

void Button::setText(const std::string& text) {
    SetWindowText(hwnd_, std::wstring(text.begin(), text.end()).c_str());
}

