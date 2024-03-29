#ifndef LISTBOX_H
#define LISTBOX_H

#include <Windows.h>
#include <string>
#include <vector>

class ListBox {
public:
    ListBox(int x, int y, int width, int height, HWND parent);
    ~ListBox();

    void addItem(const std::string& item);
    void removeItem(int index);
    int getSelectedIndex() const;
    std::string getSelectedItem() const;

private:
    HWND hwnd_;
};

#endif // LISTBOX_H
