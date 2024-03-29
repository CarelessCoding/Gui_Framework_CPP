#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <Windows.h>

class ProgressBar {
public:
    ProgressBar(int x, int y, int width, int height, HWND parent);
    ~ProgressBar();

    void setRange(int min, int max);
    void setValue(int value);
    int getValue() const;

private:
    HWND hwnd_;
};

#endif // PROGRESSBAR_H
