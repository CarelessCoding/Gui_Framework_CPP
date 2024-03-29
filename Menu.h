#ifndef MENU_H
#define MENU_H

#include <Windows.h>
#include <string>
#include <unordered_map>

class Menu {
public:
    Menu();
    ~Menu();

    void addItem(const std::string& text, UINT id);
    void addSeparator();
    void show(HWND hwnd, int x, int y);

private:
    HMENU hMenu_;
    std::unordered_map<UINT, std::string> items_; // Optional: To keep track of items
};

#endif // MENU_H

