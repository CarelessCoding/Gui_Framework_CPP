#include "ProgressBar.h"
#include <CommCtrl.h>

// Ensure that the common controls library is initialized.
#pragma comment(lib, "comctl32.lib")

ProgressBar::ProgressBar(int x, int y, int width, int height, HWND parent)
{
    // Initialize common controls.
    INITCOMMONCONTROLSEX icc;
    icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icc.dwICC = ICC_PROGRESS_CLASS;
    InitCommonControlsEx(&icc);

    hwnd_ = CreateWindowEx(0, PROGRESS_CLASS, nullptr,
                           WS_VISIBLE | WS_CHILD,
                           x, y, width, height,
                           parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

ProgressBar::~ProgressBar() {
    DestroyWindow(hwnd_);
}

void ProgressBar::setRange(int min, int max) {
    SendMessage(hwnd_, PBM_SETRANGE, 0, MAKELPARAM(min, max));
}

void ProgressBar::setValue(int value) {
    SendMessage(hwnd_, PBM_SETPOS, value, 0);
}

int ProgressBar::getValue() const {
    return SendMessage(hwnd_, PBM_GETPOS, 0, 0);
}
