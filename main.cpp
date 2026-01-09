#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

class button_functions {
    public:
    static void callback(Fl_Widget *widget, void *data) {
        Fl_Box *box = static_cast<Fl_Box*>(data);
        box->label("Button Pressed!");
    }
};

int main(int argc, char **argv) {
    Fl_Window *window = new Fl_Window(300, 300, "Test Window");
    Fl_Box *box = new Fl_Box(20, 40, 200, 100, "Hello World");
    Fl_Button *button = new Fl_Button(60, 200, 40, 50, "Press Me!");
    box->box(FL_UP_BOX);
    button->type(FL_NORMAL_BUTTON);
    button->callback(button_functions::callback, box);
    box->labelfont(FL_BOLD + FL_ITALIC);
    box->labelsize(24);
    box->labeltype(FL_SHADOW_LABEL);
    window->end();
    window->show(argc, argv);
    return Fl::run();
}
