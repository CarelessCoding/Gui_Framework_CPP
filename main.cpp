#include <Windows.h>
#include "Button.h"
#include "ComboBox.h"
#include "DateTimePicker.h"
#include "GroupBox.h"
#include "ImageView.h"
#include "Label.h"
#include "ListBox.h"
#include "ListView.h"
#include "ProgressBar.h"
#include "RadioButton.h"
#include "ScrollBar.h"
#include "Slider.h"
#include "SpinBox.h"
#include "TabControl.h"
#include "Toolbar.h"
#include "TreeView.h"
#include "TextInput.h"
#include <CommCtrl.h>
#include <functional>

// Define TOOLBARCLASSNAME before including Toolbar.h
//#define TOOLBARCLASSNAME TOOLBARCLASSNAMEW

// Forward declaration of WndProc
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Initialize common controls
    INITCOMMONCONTROLSEX icex;
    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC = ICC_BAR_CLASSES; // Enable toolbar, status bar, etc.
    InitCommonControlsEx(&icex);

    // Register window class
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MainWndClass";
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    if (!RegisterClass(&wc)) {
        MessageBox(nullptr, L"Window Registration Failed!", L"Error", MB_ICONERROR | MB_OK);
        return 1;
    }

    // Create the main application window
    HWND hwnd = CreateWindow(wc.lpszClassName, L"Win32 GUI Application",
                             WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                             800, 600, nullptr, nullptr, hInstance, nullptr);
    if (!hwnd) {
        MessageBox(nullptr, L"Window Creation Failed!", L"Error", MB_ICONERROR | MB_OK);
        return 1;
    }
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Creating various widgets in the main window
    Label label("Label", 10, 10, 100, 20, hwnd);
    Button button("Button", 10, 40, 100, 30, hwnd, []() {});
    ComboBox comboBox(10, 80, 100, 200, hwnd);
    DateTimePicker dateTimePicker(10, 120, 200, 20, hwnd);
    GroupBox groupBox("Group Box", 10, 150, 200, 100, hwnd);
    ImageView imageView(10, 260, 100, 100, hwnd, nullptr);
    ListBox listBox(220, 10, 100, 100, hwnd);
    ListView listView(220, 120, 200, 100, hwnd);
    ProgressBar progressBar(220, 230, 200, 20, hwnd);
    RadioButton radioButton("Radio Button", 220, 260, 150, 30, hwnd, false);
    ScrollBar scrollBar(220, 300, 200, 20, hwnd, true);
    Slider slider(220, 330, 200, 30, hwnd, 0, 100, 50);
    SpinBox spinBox(220, 370, 100, 20, hwnd, 0, 100, 50);
    TabControl tabControl(220, 400, 200, 100, hwnd);
    Toolbar toolbar(hwnd, 400, 30);
    TreeView treeView(10, 370, 200, 100, hwnd);
    TextInput inputBox(10, 480, 200, 20, hwnd);
    TextInput outputBox(220, 480, 200, 20, hwnd);
    outputBox.setReadOnly(true);

    // Add items to ComboBox, ListBox, ListView, and TabControl
    comboBox.addItem("Item 1");
    comboBox.addItem("Item 2");
    listBox.addItem("Item 1");
    listBox.addItem("Item 2");


    // Assuming addColumn expects a title, width, and format alignment
    listView.addColumn(L"Column 1", 100, LVCFMT_LEFT);
    listView.addColumn(L"Column 2", 100, LVCFMT_LEFT);

    // Assuming addItem expects text and an identifier/index
    listView.addItem(L"Row 1", 0);
    listView.setItemText(0, 1, L"Data 1");
    tabControl.addTab("Tab 1");
    tabControl.addTab("Tab 2");

    // Set text in TextInput and TextOutput
    inputBox.setText(L"Enter text here...");
    outputBox.setText(L"Output text...");

    // Main message loop
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
