#ifndef SLIDER_H
#define SLIDER_H

#include <Windows.h>

class Slider {
public:
    Slider(int x, int y, int width, int height, HWND parent, int min, int max, int value);
    ~Slider();

    void setValue(int value);
    int getValue() const;

private:
    HWND hwnd_;
};

#endif // SLIDER_H
