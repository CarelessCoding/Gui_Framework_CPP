#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <Windows.h>
#include <CommCtrl.h>
#include <string>  // Add this line

class ListView {
public:
    ListView(int x, int y, int width, int height, HWND parent);
    ~ListView();

    void addColumn(const std::wstring& header, int width, int index);
    void addItem(const std::wstring& text, int index);
    void setItemText(int row, int col, const std::wstring& text);

private:
    HWND hwnd_;
};

#endif // LISTVIEW_H
