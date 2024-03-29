#ifndef GROUPBOX_H
#define GROUPBOX_H

#include <Windows.h>
#include <string>

class GroupBox {
public:
    GroupBox(const std::string& text, int x, int y, int width, int height, HWND parent);
    ~GroupBox();

private:
    HWND hwnd_;
};

#endif // GROUPBOX_H
