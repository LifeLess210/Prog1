#include "Simple_window.h"
#include "Graph.h"

struct B1
{
public:
	virtual void vf()
	{
		cout << "B1::vf\n";
	}
	void f()
	{
		cout << "B1:f\n";
	}
	virtual void pvf() = 0; //<-- komment ha az első fele kell hogy működjön
};

struct D1 : B1
{
public:
	void vf()
	{
		cout << "D1::vf\n";
	}
	void f()
	{
		cout << "D1:f\n";
	}
};

struct D2 : D1
{
public:
	void pvf() override
	{
		cout << "D2::pvf\n";
	}
};

struct B2
{
public:
	virtual void pvf() = 0;
};

struct D21 : B2
{
public:
	string str = "sztring";
	void pvf() override
	{
		cout << str << "\n";
	}
};

struct D22 : B2
{
public:
	int szam = 10;
	void pvf() override
	{
		cout << szam << "\n";
	}
};

void f(B2& b2)
{
	b2.pvf();
}

int main()
{
	//Első fél
	/*B1 b1;
	b1.vf();
	b1.f();

	D1 d1;
	d1.vf();
	d1.f();

	B1& reference (d1);
	reference.vf();
	reference.f();*/

	//Második fél

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	D21 d21;
	f(d21);

	D22 d22;
	f(d22);
}