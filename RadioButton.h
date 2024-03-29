#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include <string>
#include <Windows.h>

class RadioButton {
public:
    RadioButton(const std::string& text, int x, int y, int width, int height, HWND parent, bool checked = false);
    ~RadioButton();

    void setChecked(bool checked);
    bool isChecked() const;

private:
    HWND hwnd_;
};

#endif // RADIOBUTTON_H
