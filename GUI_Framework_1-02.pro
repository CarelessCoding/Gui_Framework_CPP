LIBS += -lUser32 -lGdi32 "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.20348.0/um/x64/comctl32.lib"
TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Button.cpp \
        ComboBox.cpp \
        DateTimePicker.cpp \
        EventSystem.cpp \
        GroupBox.cpp \
        ImageView.cpp \
        Label.cpp \
        ListBox.cpp \
        ListView.cpp \
        Menu.cpp \
        ProgressBar.cpp \
        RadioButton.cpp \
        ScrollBar.cpp \
        Slider.cpp \
        SpinBox.cpp \
        TabControl.cpp \
        TextInput.cpp \
        Toolbar.cpp \
        TreeView.cpp \
        Window.cpp \
        main.cpp

HEADERS += \
    Button.h \
    ComboBox.h \
    DateTimePicker.h \
    EventSystem.h \
    GroupBox.h \
    ImageView.h \
    Label.h \
    ListBox.h \
    ListView.h \
    Menu.h \
    ProgressBar.h \
    RadioButton.h \
    ScrollBar.h \
    Slider.h \
    SpinBox.h \
    TabControl.h \
    TextInput.h \
    Toolbar.h \
    TreeView.h \
    Widget.h \
    Window.h
