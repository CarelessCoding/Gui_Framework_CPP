#include "ListBox.h"

ListBox::ListBox(int x, int y, int width, int height, HWND parent) {
    hwnd_ = CreateWindowEx(0, L"LISTBOX", nullptr,
                           WS_VISIBLE | WS_CHILD | WS_BORDER | LBS_NOTIFY,
                           x, y, width, height,
                           parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

ListBox::~ListBox() {
    DestroyWindow(hwnd_);
}

void ListBox::addItem(const std::string& item) {
    SendMessage(hwnd_, LB_ADDSTRING, 0, (LPARAM)std::wstring(item.begin(), item.end()).c_str());
}

void ListBox::removeItem(int index) {
    SendMessage(hwnd_, LB_DELETESTRING, (WPARAM)index, 0);
}

int ListBox::getSelectedIndex() const {
    return (int)SendMessage(hwnd_, LB_GETCURSEL, 0, 0);
}

std::string ListBox::getSelectedItem() const {
    int index = getSelectedIndex();
    if (index == LB_ERR) {
        return "";
    }
    int length = (int)SendMessage(hwnd_, LB_GETTEXTLEN, (WPARAM)index, 0);
    std::vector<wchar_t> buffer(length + 1);
    SendMessage(hwnd_, LB_GETTEXT, (WPARAM)index, (LPARAM)buffer.data());
    return std::string(buffer.begin(), buffer.end());
}
