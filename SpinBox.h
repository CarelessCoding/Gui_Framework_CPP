#ifndef SPINBOX_H
#define SPINBOX_H

#include <Windows.h>

class SpinBox {
public:
    SpinBox(int x, int y, int width, int height, HWND parent, int min, int max, int value);
    ~SpinBox();

    void setValue(int value);
    int getValue() const;

private:
    HWND hwnd_;
    HWND hwndUpDown_;
};

#endif // SPINBOX_H
