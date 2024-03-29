#ifndef LABEL_H
#define LABEL_H

#include <string>
#include <Windows.h>

class Label {
public:
    Label(const std::string& text, int x, int y, int width, int height, HWND parent);
    ~Label();

    void setText(const std::string& text);

private:
    HWND hwnd_;
    std::string text_;
};

#endif // LABEL_H
