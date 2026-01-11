#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Menu_Bar.H>

void save_cb() {
    std::cout << "Save callback triggered!" << std::endl;
}

int main(int argc, char **argv) {
    Fl_Window *window = new Fl_Window(500, 500, "Text Editor");
    Fl_Menu_Bar *menubar = new Fl_Menu_Bar(0, 0, 500, 25);
    Fl_Multiline_Input *multiline_input = new Fl_Multiline_Input(20, 160, 200, 80, "Multiline Input");
    Fl_Menu_Item menuItems[] = {
        {"&File", 0, 0, 0, FL_SUBMENU},
            {"&New", 0, 0, 0},
            {"&Open", 0, 0, 0},
            {"&Save", 0, (Fl_Callback *)[](Fl_Widget*, void*) {save_cb();}, 0},
            {"&Save As...", 0, 0, 0},
            {0},
            {"E&xit", 0, (Fl_Callback *)[](Fl_Widget*, void*) { exit(0); }, 0},
            {0},
        {0}
    };
    menubar->copy(menuItems);
    window->end();
    window->show(argc, argv);
    return Fl::run();
}
