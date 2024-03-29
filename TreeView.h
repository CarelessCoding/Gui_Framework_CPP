#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <Windows.h>
#include <CommCtrl.h>
#include <string>  // Add this line

class TreeView {
public:
    TreeView(int x, int y, int width, int height, HWND parent);
    ~TreeView();

    HTREEITEM addItem(HTREEITEM parent, const std::wstring& text);
    void removeItem(HTREEITEM item);
    HTREEITEM getSelectedItem() const;

private:
    HWND hwnd_;
};

#endif // TREEVIEW_H
