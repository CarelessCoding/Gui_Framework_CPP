#include "DateTimePicker.h"

DateTimePicker::DateTimePicker(int x, int y, int width, int height, HWND parent) {
    hwnd_ = CreateWindowEx(0, DATETIMEPICK_CLASS, nullptr,
                           WS_VISIBLE | WS_CHILD | DTS_SHORTDATEFORMAT,
                           x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

DateTimePicker::~DateTimePicker() {
    DestroyWindow(hwnd_);
}

SYSTEMTIME DateTimePicker::getDateTime() const {
    SYSTEMTIME dateTime;
    DateTime_GetSystemtime(hwnd_, &dateTime);
    return dateTime;
}

void DateTimePicker::setDateTime(const SYSTEMTIME& dateTime) {
    DateTime_SetSystemtime(hwnd_, GDT_VALID, &dateTime);
}
