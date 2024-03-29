Label
Creation: Label label("Label", 10, 10, 100, 20, hwnd);
Usage: Displays static text.
Button
Creation: Button button("Button", 10, 40, 100, 30, hwnd, []() {});
Usage: A clickable button that can trigger an action.
ComboBox
Creation: ComboBox comboBox(10, 80, 100, 200, hwnd);
Usage: A drop-down list that allows the user to select one item from a list.
DateTimePicker
Creation: DateTimePicker dateTimePicker(10, 120, 200, 20, hwnd);
Usage: Allows the user to select a date and/or time.
GroupBox
Creation: GroupBox groupBox("Group Box", 10, 150, 200, 100, hwnd);
Usage: A container for grouping other controls with an optional title.
ImageView
Creation: ImageView imageView(10, 260, 100, 100, hwnd, nullptr);
Usage: Displays an image.
ListBox
Creation: ListBox listBox(220, 10, 100, 100, hwnd);
Usage: Displays a list of items.
ListView
Creation: ListView listView(220, 120, 200, 100, hwnd);
Usage: Displays a list of items with optional columns.
ProgressBar
Creation: ProgressBar progressBar(220, 230, 200, 20, hwnd);
Usage: Displays the progress of a task.
RadioButton
Creation: RadioButton radioButton("Radio Button", 220, 260, 150, 30, hwnd, false);
Usage: Allows the user to select one option from a set.
ScrollBar
Creation: ScrollBar scrollBar(220, 300, 200, 20, hwnd, true);
Usage: Allows the user to scroll through content.
Slider
Creation: Slider slider(220, 330, 200, 30, hwnd, 0, 100, 50);
Usage: Allows the user to select a value from a range.
SpinBox
Creation: SpinBox spinBox(220, 370, 100, 20, hwnd, 0, 100, 50);
Usage: Allows the user to select a numeric value.
TabControl
Creation: TabControl tabControl(220, 400, 200, 100, hwnd);
Usage: Provides a tabbed interface.
Toolbar
Creation: Toolbar toolbar(hwnd, 400, 30);
Usage: Provides a toolbar for user interaction.
TreeView
Creation: TreeView treeView(10, 370, 200, 100, hwnd);
Usage: Displays a hierarchical list of items.
TextInput
Creation: TextInput inputBox(10, 480, 200, 20, hwnd);
Usage: Allows the user to input text.
