#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <Windows.h>
#include <string>

class TextInput {
public:
    TextInput(int x, int y, int width, int height, HWND parent);
    ~TextInput();

    std::wstring getText() const;
    void setText(const std::wstring& text);
    void setReadOnly(bool readOnly);

private:
    HWND hwnd_;
};

#endif // TEXTINPUT_H
