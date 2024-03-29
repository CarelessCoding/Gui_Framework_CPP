#include "TabControl.h"
#include <CommCtrl.h>

TabControl::TabControl(int x, int y, int width, int height, HWND parent) {
    INITCOMMONCONTROLSEX icex;
    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC = ICC_TAB_CLASSES;
    InitCommonControlsEx(&icex);

    hwnd_ = CreateWindowEx(0, WC_TABCONTROL, nullptr,
                           WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE,
                           x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

TabControl::~TabControl() {
    DestroyWindow(hwnd_);
}

void TabControl::addTab(const std::string& title) {
    // Convert std::string to std::wstring
    std::wstring wtitle(title.begin(), title.end());

    TCITEM tie;
    tie.mask = TCIF_TEXT;
    tie.iImage = -1;
    tie.pszText = const_cast<wchar_t*>(wtitle.c_str());

    TabCtrl_InsertItem(hwnd_, tabTitles_.size(), &tie);
    tabTitles_.push_back(title);
}

int TabControl::getSelectedIndex() const {
    return TabCtrl_GetCurSel(hwnd_);
}
