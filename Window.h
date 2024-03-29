#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>
#include <string>

class Window {
public:
    Window(int width, int height, const std::wstring& title);
    ~Window();

    HWND getHandle() const;

private:
    HWND hwnd_;
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
};

#endif // WINDOW_H
