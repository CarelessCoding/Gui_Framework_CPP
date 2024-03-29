#include "Toolbar.h"

Toolbar::Toolbar(HWND parent, int width, int height) {
    hwnd_ = CreateWindowEx(0, TOOLBARCLASSNAME, nullptr,
                           WS_CHILD | WS_VISIBLE | TBSTYLE_WRAPABLE | TBSTYLE_TOOLTIPS,
                           0, 0, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);

    if (!hwnd_) {
        DWORD error = GetLastError();
        std::string errorMessage = "Failed to create toolbar. Error code: " + std::to_string(error);
        throw std::runtime_error(errorMessage);
    }

    SendMessage(hwnd_, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
}

Toolbar::~Toolbar() {
    DestroyWindow(hwnd_);
}

void Toolbar::addButton(int id, int imageIndex, const std::wstring& tooltip) {
    TBBUTTON button = {};
    button.iBitmap = imageIndex;
    button.idCommand = id;
    button.fsState = TBSTATE_ENABLED;
    button.fsStyle = TBSTYLE_BUTTON;
    button.iString = (INT_PTR)tooltip.c_str();

    buttons_.push_back(button);
    SendMessage(hwnd_, TB_ADDBUTTONS, (WPARAM)1, (LPARAM)&buttons_.back());
}

void Toolbar::addSeparator() {
    TBBUTTON button = {};
    button.fsStyle = TBSTYLE_SEP;

    buttons_.push_back(button);
    SendMessage(hwnd_, TB_ADDBUTTONS, (WPARAM)1, (LPARAM)&buttons_.back());
}
