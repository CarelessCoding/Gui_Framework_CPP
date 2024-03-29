#ifndef BUTTON_H
#define BUTTON_H

#include <Windows.h>
#include <functional>
#include <string>

class Button {
public:
    Button(const std::string& text, int x, int y, int width, int height, HWND parent, std::function<void()> onClick);
    ~Button();

    void setText(const std::string& text);
    HWND getHandle() const;
    std::function<void()> getOnClick() const;

private:
    HWND hwnd_;
    std::function<void()> onClick_;
};

#endif // BUTTON_H
