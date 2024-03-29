#include "TreeView.h"

TreeView::TreeView(int x, int y, int width, int height, HWND parent) {
    hwnd_ = CreateWindowEx(0, WC_TREEVIEW, nullptr,
                           WS_VISIBLE | WS_CHILD | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS,
                           x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

TreeView::~TreeView() {
    DestroyWindow(hwnd_);
}

HTREEITEM TreeView::addItem(HTREEITEM parent, const std::wstring& text) {
    TVINSERTSTRUCT tvis = {0};
    tvis.hParent = parent;
    tvis.hInsertAfter = TVI_LAST;
    tvis.item.mask = TVIF_TEXT;
    tvis.item.pszText = const_cast<LPWSTR>(text.c_str());

    return TreeView_InsertItem(hwnd_, &tvis);
}

void TreeView::removeItem(HTREEITEM item) {
    TreeView_DeleteItem(hwnd_, item);
}

HTREEITEM TreeView::getSelectedItem() const {
    return TreeView_GetSelection(hwnd_);
}
