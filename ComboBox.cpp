#include "ComboBox.h"

ComboBox::ComboBox(int x, int y, int width, int height, HWND parent) {
    hwnd_ = CreateWindowEx(0, L"COMBOBOX", nullptr,
                           WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
                           x, y, width, height,
                           parent, nullptr, GetModuleHandle(nullptr), nullptr);
}


ComboBox::~ComboBox() {
    DestroyWindow(hwnd_);
}

void ComboBox::addItem(const std::string& item) {
    SendMessage(hwnd_, CB_ADDSTRING, 0, (LPARAM)item.c_str());
}

void ComboBox::removeItem(int index) {
    SendMessage(hwnd_, CB_DELETESTRING, (WPARAM)index, 0);
}

int ComboBox::getSelectedIndex() const {
    return (int)SendMessage(hwnd_, CB_GETCURSEL, 0, 0);
}

std::string ComboBox::getSelectedItem() const {
    int index = getSelectedIndex();
    if (index == CB_ERR) {
        return "";
    }
    int length = (int)SendMessage(hwnd_, CB_GETLBTEXTLEN, (WPARAM)index, 0);
    std::vector<char> buffer(length + 1);
    SendMessage(hwnd_, CB_GETLBTEXT, (WPARAM)index, (LPARAM)buffer.data());
    return std::string(buffer.data());
}
