#include "Menu.h"

Menu::Menu() {
    hMenu_ = CreatePopupMenu();
}

Menu::~Menu() {
    DestroyMenu(hMenu_);
}

void Menu::addItem(const std::string& text, UINT id) {
    AppendMenuA(hMenu_, MF_STRING, id, text.c_str());
    items_[id] = text;
}

void Menu::addSeparator() {
    AppendMenuA(hMenu_, MF_SEPARATOR, 0, nullptr);
}

void Menu::show(HWND hwnd, int x, int y) {
    TrackPopupMenu(hMenu_, TPM_LEFTALIGN | TPM_TOPALIGN | TPM_NOANIMATION, x, y, 0, hwnd, nullptr);
}
