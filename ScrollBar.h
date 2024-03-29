#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <Windows.h>

class ScrollBar {
public:
    ScrollBar(int x, int y, int width, int height, HWND parent, bool horizontal);
    ~ScrollBar();

    void setRange(int min, int max);
    void setThumbPosition(int pos);

private:
    HWND hwnd_;
};

#endif // SCROLLBAR_H
