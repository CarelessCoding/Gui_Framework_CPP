#include "ImageView.h"

ImageView::ImageView(int x, int y, int width, int height, HWND parent, HBITMAP image) {
    hwnd_ = CreateWindowEx(0, L"STATIC", nullptr,
                           WS_VISIBLE | WS_CHILD | SS_BITMAP,
                           x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);
    SendMessage(hwnd_, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)image);
}

ImageView::~ImageView() {
    DestroyWindow(hwnd_);
}
