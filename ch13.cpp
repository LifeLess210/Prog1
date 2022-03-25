#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	//1.

	Point tl{0, 0};

	int x_size = 1000;
	int y_size = 800;

	Simple_window win{tl, x_size, y_size, "Window"};

	//2.

	Lines grid;

	int x_grid = 100;
	int y_grid = 100;
	int x_grid_size = 800;
	int y_grid_size = 800;

	for(int x = 100; x <= x_grid_size; x= x+x_grid)
	{
		grid.add(Point{x, 0}, Point{x, y_grid_size});	//függőleges
	}
	for(int y = 0; y <= y_grid_size; y=y+y_grid)
	{
		grid.add(Point{0, y}, Point{x_grid_size, y});	//vízszintes
	}

	win.attach(grid);

	//3.

	Vector_ref<Rectangle> re;
	for(int i = 0; i < 800; i=i+100)
	{
		re.push_back(new Rectangle{Point{i,i},Point{i+100,i+100}});
	}
	for(int i = 0; i < re.size(); i++)
	{
		re[i].set_fill_color(Color::red);
		win.attach(re[i]);
	}

	//4.

	Image i1{Point{0,200},"image.jpg"};
	Image i2{Point{0,400},"image.jpg"};
	Image i3{Point{0,600},"image.jpg"};

	win.attach(i1);
	win.attach(i2);
	win.attach(i3);

	//5.

	Image i4{Point{0,0},"kep.jpg"};
	win.attach(i4);
	win.wait_for_button();
	for(int i = 1; i <= 64; i++)
	{
		if(i==64)
		{
			i = 0;
			i4.move(-700,-700);
			win.wait_for_button();
		}
		else if(i%8 == 0)
		{
			i4.move(-700,100);
			win.wait_for_button();
		}
		else
		{
			i4.move(100,0);
			win.wait_for_button();
		}
	}

		win.wait_for_button();
}
