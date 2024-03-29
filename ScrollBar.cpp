#include "ScrollBar.h"

ScrollBar::ScrollBar(int x, int y, int width, int height, HWND parent, bool horizontal)
{
    hwnd_ = CreateWindowEx(0, L"SCROLLBAR", nullptr,
                           WS_VISIBLE | WS_CHILD | (horizontal ? SBS_HORZ : SBS_VERT),
                           x, y, width, height,
                           parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

ScrollBar::~ScrollBar() {
    DestroyWindow(hwnd_);
}

void ScrollBar::setRange(int min, int max) {
    SetScrollRange(hwnd_, SB_CTL, min, max, TRUE);
}

void ScrollBar::setThumbPosition(int pos) {
    SetScrollPos(hwnd_, SB_CTL, pos, TRUE);
}
