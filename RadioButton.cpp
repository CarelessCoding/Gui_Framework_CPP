#include "RadioButton.h"

RadioButton::RadioButton(const std::string& text, int x, int y, int width, int height, HWND parent, bool checked)
{
    hwnd_ = CreateWindowEx(0, L"BUTTON", std::wstring(text.begin(), text.end()).c_str(),
                           WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | (checked ? WS_GROUP | WS_TABSTOP : 0),
                           x, y, width, height,
                           parent, nullptr, GetModuleHandle(nullptr), nullptr);

    if (checked) {
        setChecked(true);
    }
}

RadioButton::~RadioButton() {
    DestroyWindow(hwnd_);
}

void RadioButton::setChecked(bool checked) {
    SendMessage(hwnd_, BM_SETCHECK, (WPARAM)(checked ? BST_CHECKED : BST_UNCHECKED), 0);
}

bool RadioButton::isChecked() const {
    return SendMessage(hwnd_, BM_GETCHECK, 0, 0) == BST_CHECKED;
}
