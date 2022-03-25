#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title):Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point", [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit", [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},
    style_menu{Point{x_max() - 300, 80}, 150, 40,  Menu::vertical, "style"},
    style_button{Point{x_max() - 300, 80}, 150, 40, "style", [](Address, Address pw) {reference_to<Lines_window>(pw).style_pressed();}},
    color_menu{Point{x_max() - 150, 80}, 150, 40,  Menu::vertical, "color"},
    color_button{Point{x_max() - 150, 80}, 150, 40, "color", [](Address, Address pw) {reference_to<Lines_window>(pw).color_pressed();}}
    
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    color_menu.attach(new Button{Point{150, 80},150,40,"red", [](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}});
    color_menu.attach(new Button{Point{150, 120},150,40,"green", [](Address, Address pw) {reference_to<Lines_window>(pw).green_pressed();}});
    color_menu.attach(new Button{Point{150, 160},150,40,"blue", [](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}});
    style_menu.attach(new Button{Point{300, 80},150,40,"dotted", [](Address, Address pw) {reference_to<Lines_window>(pw).dotted_pressed();}});
    style_menu.attach(new Button{Point{300, 120},150,40,"dash", [](Address, Address pw) {reference_to<Lines_window>(pw).dashed_pressed();}});
    style_menu.attach(new Button{Point{300, 160},150,40,"solid", [](Address, Address pw) {reference_to<Lines_window>(pw).solid_pressed();}});
    attach(style_menu);
    attach(color_menu);

    style_menu.hide();
    color_menu.hide();
    

    attach(color_button);
    attach(style_button);
    attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}