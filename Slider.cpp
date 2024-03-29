#include "Slider.h"
#include <CommCtrl.h>

Slider::Slider(int x, int y, int width, int height, HWND parent, int min, int max, int value)
{
    hwnd_ = CreateWindow(TRACKBAR_CLASS, nullptr,
                         WS_VISIBLE | WS_CHILD | TBS_HORZ,
                         x, y, width, height,
                         parent, nullptr, nullptr, nullptr);
    SendMessage(hwnd_, TBM_SETRANGE, TRUE, MAKELPARAM(min, max));
    setValue(value);
}

Slider::~Slider() {
    DestroyWindow(hwnd_);
}

void Slider::setValue(int value) {
    SendMessage(hwnd_, TBM_SETPOS, TRUE, value);
}

int Slider::getValue() const {
    return SendMessage(hwnd_, TBM_GETPOS, 0, 0);
}
