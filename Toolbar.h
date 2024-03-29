#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <Windows.h>
#include <CommCtrl.h>
#include <vector>
#include <string>
#include <stdexcept>

class Toolbar {
public:
    Toolbar(HWND parent, int width, int height);
    ~Toolbar();

    void addButton(int id, int imageIndex, const std::wstring& tooltip);
    void addSeparator();

private:
    HWND hwnd_;
    std::vector<TBBUTTON> buttons_;
};

#endif // TOOLBAR_H
