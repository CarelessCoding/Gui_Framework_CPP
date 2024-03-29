#include "SpinBox.h"
#include <CommCtrl.h>
#include <sstream>

SpinBox::SpinBox(int x, int y, int width, int height, HWND parent, int min, int max, int value) {
    hwnd_ = CreateWindowEx(0, UPDOWN_CLASS, nullptr,
                           WS_CHILD | WS_VISIBLE | UDS_ALIGNRIGHT | UDS_SETBUDDYINT | UDS_ARROWKEYS,
                           x, y, width, height,
                           parent, nullptr, GetModuleHandle(nullptr), nullptr);

    SendMessage(hwndUpDown_, UDM_SETBUDDY, (WPARAM)hwnd_, 0);
    SendMessage(hwndUpDown_, UDM_SETRANGE32, min, max);
    SendMessage(hwndUpDown_, UDM_SETPOS32, 0, value);
}

SpinBox::~SpinBox() {
    DestroyWindow(hwndUpDown_);
    DestroyWindow(hwnd_);
}

void SpinBox::setValue(int value) {
    std::wstringstream ws;
    ws << value;
    SetWindowText(hwnd_, ws.str().c_str());
}

int SpinBox::getValue() const {
    wchar_t buffer[256];
    GetWindowText(hwnd_, buffer, sizeof(buffer) / sizeof(wchar_t));
    return _wtoi(buffer);
}
