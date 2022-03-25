#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	Button style_button;
	Menu style_menu;
	void change_style(Line_style s)
	{
		lines.set_style(s);
	}
	void hide_style()
	{
		style_menu.hide();
		style_button.show();
	}
	void style_pressed()
	{
		style_button.hide();
		style_menu.show();
	}
	void solid_pressed()
	{
		change_style(Line_style::solid);
		hide_style();
	}
	void dotted_pressed()
	{
		change_style(Line_style::dot);
		hide_style();
	}
	void dashed_pressed()
	{
		change_style(Line_style::dash);
		hide_style();
	}
	

	Button color_button;
	Menu color_menu;
	void change_color(Color c)
	{
		lines.set_color(c);
	}
	void hide_color()
	{
		color_menu.hide();
		color_button.show();
	}
	void color_pressed()
	{
	 	color_button.hide();
	 	color_menu.show();
	}
	void red_pressed()
	{
		change_color(Color::red);
		hide_color();
	}
	void green_pressed()
	{
		change_color(Color::green);
		hide_color();
	}
	void blue_pressed()
	{
		change_color(Color::blue);
		hide_color();
	}
	void next();
	void quit();

};