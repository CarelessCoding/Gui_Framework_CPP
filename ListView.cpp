#include "ListView.h"

ListView::ListView(int x, int y, int width, int height, HWND parent) {
    hwnd_ = CreateWindowEx(0, WC_LISTVIEW, nullptr,
                           WS_VISIBLE | WS_CHILD | LVS_REPORT,
                           x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);
    ListView_SetExtendedListViewStyle(hwnd_, LVS_EX_FULLROWSELECT);
}

ListView::~ListView() {
    DestroyWindow(hwnd_);
}

void ListView::addColumn(const std::wstring& header, int width, int index) {
    LVCOLUMN lvc = {0};
    lvc.mask = LVCF_TEXT | LVCF_WIDTH;
    lvc.pszText = const_cast<LPWSTR>(header.c_str());
    lvc.cx = width;

    ListView_InsertColumn(hwnd_, index, &lvc);
}

void ListView::addItem(const std::wstring& text, int index) {
    LVITEM lvi = {0};
    lvi.mask = LVIF_TEXT;
    lvi.pszText = const_cast<LPWSTR>(text.c_str());
    lvi.iItem = index;

    ListView_InsertItem(hwnd_, &lvi);
}

void ListView::setItemText(int row, int col, const std::wstring& text) {
    ListView_SetItemText(hwnd_, row, col, const_cast<LPWSTR>(text.c_str()));
}
