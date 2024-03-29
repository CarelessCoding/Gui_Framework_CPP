#ifndef WIDGET_H
#define WIDGET_H

// Base class for all GUI components
class Widget {
public:
    virtual void draw() = 0; // Pure virtual function for drawing the widget
    virtual ~Widget() = default; // Virtual destructor
};

#endif // WIDGET_H
