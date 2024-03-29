#ifndef DATETIMEPICKER_H
#define DATETIMEPICKER_H

#include <Windows.h>
#include <CommCtrl.h>

class DateTimePicker {
public:
    DateTimePicker(int x, int y, int width, int height, HWND parent);
    ~DateTimePicker();

    SYSTEMTIME getDateTime() const;
    void setDateTime(const SYSTEMTIME& dateTime);

private:
    HWND hwnd_;
};

#endif // DATETIMEPICKER_H
