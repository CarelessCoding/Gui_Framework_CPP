#ifndef TABCONTROL_H
#define TABCONTROL_H

#include <Windows.h>
#include <string>
#include <vector>

class TabControl {
public:
    TabControl(int x, int y, int width, int height, HWND parent);
    ~TabControl();

    void addTab(const std::string& title);
    int getSelectedIndex() const;

private:
    HWND hwnd_;
    std::vector<std::string> tabTitles_;
};

#endif // TABCONTROL_H
