#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <Windows.h>

class ImageView {
public:
    ImageView(int x, int y, int width, int height, HWND parent, HBITMAP image);
    ~ImageView();

private:
    HWND hwnd_;
};

#endif // IMAGEVIEW_H
