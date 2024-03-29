#include "TextInput.h"

TextInput::TextInput(int x, int y, int width, int height, HWND parent) {
    hwnd_ = CreateWindowEx(0, L"EDIT", nullptr,
                           WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                           x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

TextInput::~TextInput() {
    DestroyWindow(hwnd_);
}

std::wstring TextInput::getText() const {
    int length = GetWindowTextLength(hwnd_) + 1;
    std::wstring text(length, L'\0');
    GetWindowText(hwnd_, &text[0], length);
    text.resize(length - 1);  // Remove the extra null terminator
    return text;
}

void TextInput::setText(const std::wstring& text) {
    SetWindowText(hwnd_, text.c_str());
}

void TextInput::setReadOnly(bool readOnly) {
    DWORD style = GetWindowLong(hwnd_, GWL_STYLE);
    if (readOnly) {
        style |= ES_READONLY;
    } else {
        style &= ~ES_READONLY;
    }
    SetWindowLong(hwnd_, GWL_STYLE, style);
    InvalidateRect(hwnd_, nullptr, TRUE);
}
