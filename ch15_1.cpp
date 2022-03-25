#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return slope(x) + cos(x); }

int main()
{
	using namespace Graph_lib;

	Point p{100,100};
	Simple_window win{p, 600, 600, "Win"};

	Point x_axis_start{100,300};
	Point y_axis_start{300,500};

	Point origo{300,300};

	int x_axis_length = 400;
	int y_axis_length = 400;

	int x_scale = 20;
	int y_scale = 20;

	Axis x{Axis::x,x_axis_start,x_axis_length,x_scale,"1 == 20 pixels"};
	Axis y{Axis::y,y_axis_start,y_axis_length,y_scale,"1 == 20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);

	Function f1{one, -10, 11, origo, 400, 20, 20};
	Function f2{slope, -10, 11, origo, 400, 20, 20};
	Function f3{square, -10, 11, origo, 400, 20, 20};
	Function f4{cos, -10, 11, origo, 400, 20, 20};
	Function f5{sloping_cos, -10, 11, origo, 400, 20, 20};

	f4.set_color(Color::blue);

	Text t1{Point{100,380},"x/2"};

	win.attach(f1);
	win.attach(f2);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);

	win.attach(t1);



	win.wait_for_button();
}
