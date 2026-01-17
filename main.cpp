#include <iostream>
#include <fstream>
#include <filesystem>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Menu_Bar.H>

void save_cb(Fl_Widget*, void* data) {
    Fl_Multiline_Input* input = static_cast<Fl_Multiline_Input*>(data);
    const char* text = input->value();
    const char* homeDir = std::getenv("HOME");
    if(!homeDir){
        std::cerr << "Home Environment not Set\n";
        return;
    }
    std::filesystem::path filePath = std::string(homeDir) + "/output.txt";
    std::fstream file(filePath, std::ios::out);
    if (file.is_open()) {
        file << text << std::endl;
        file.close();
        std::cout << "File saved successfully.\n";
    } else {
        std::cerr << "Error opening file for writing.\n";
    }
}

void open_cb(Fl_Widget*, void* data){
    Fl_Multiline_Input* input = static_cast<Fl_Multiline_Input*>(data);
    const char* text = input->value();
    const char* homeDir = std::getenv("HOME");
    if(!homeDir){
        std::cerr << "Home Environment not Set\n";
        return;
    }
    std::filesystem::path filePath = std::string(homeDir) + "/output.txt";    
    std::fstream file(filePath, std::ios::in);
    if (file.is_open()) {
        std::string line;
        std::string content;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        input->value(content.c_str());
        file.close();
        std::cout << "File opened successfully.\n";
    } else {
        std::cerr << "Error opening file for reading.\n";
    }
}

int main(int argc, char **argv) {
    Fl_Window *window = new Fl_Window(500, 500, "Text Editor");
    Fl_Menu_Bar *menubar = new Fl_Menu_Bar(0, 0, 500, 25);
    Fl_Multiline_Input *multiline_input = new Fl_Multiline_Input(0, 25, 500, 475);
    Fl_Menu_Item menuItems[] = {
        {"&File", 0, 0, 0, FL_SUBMENU},
            {"&New", 0, 0, 0},
            {"&Open", 0, open_cb, multiline_input, 0},
            {"&Save", 0, save_cb, multiline_input, 0},
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
