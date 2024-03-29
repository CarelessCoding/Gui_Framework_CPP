#include "Window.h"

Window::Window(int width, int height, const std::wstring& title) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Window::WndProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = L"WindowClass";
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    hwnd_ = CreateWindowEx(0, L"WindowClass", title.c_str(),
                           WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                           width, height, nullptr, nullptr, GetModuleHandle(nullptr), nullptr);

    ShowWindow(hwnd_, SW_SHOW);
    UpdateWindow(hwnd_);
}

Window::~Window() {
    DestroyWindow(hwnd_);
}

HWND Window::getHandle() const {
    return hwnd_;
}

LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
