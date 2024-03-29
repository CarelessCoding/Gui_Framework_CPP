#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <Windows.h>
#include <string>
#include <vector>

class ComboBox {
public:
    ComboBox(int x, int y, int width, int height, HWND parent);
    ~ComboBox();

    void addItem(const std::string& item);
    void removeItem(int index);
    int getSelectedIndex() const;
    std::string getSelectedItem() const;

private:
    HWND hwnd_;
};

#endif // COMBOBOX_H
