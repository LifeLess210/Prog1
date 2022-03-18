#include "std_lib_facilities.h"
#include "iostream"

struct Person
{
	Person(){};
	Person(string f_name, string l_name, int a);
	string fi_name()
	{
		return first_name;
	}
	string la_name()
	{
		return last_name;
	}
	int kor()
	{
		return age;
	}
private:
	string first_name;
	string last_name;
	int age;
};

Person::Person(string f_name, string l_name, int a) : first_name{f_name}, last_name{l_name}, age{a}
{
	if(a<0 || a>150) error("Invalid age");
	string full_name = f_name + " " + l_name;
	char c = ' ';
	for (int i = 0; i < full_name.length(); i++)
	{
		c = full_name[i];
		if(c == ';' || c == ':' || c == '"' || c == '[' || c == ']' || c == '*' || c == '&' || c == '^' || c== '%' || c == '$' || c == '#' || c == '@' || c == '!' )
		{
			error("invalid name");
		}
	}
}

ostream& operator<<(ostream& os, Person& p)
{
	return os << p.fi_name() << " " << p.la_name() << " " << p.kor(); 
}

istream& operator>>(istream& is, Person& p)
{
	string first_name;
	string last_name;
	int age;
	is >> first_name >> last_name >> age;
	p = Person(first_name, last_name, age);
	return is;
}

int main()
{
	vector<Person> v;
	Person p;
	string sor = "";
	while(cin >> p)
	{
		if(p.fi_name() == "x" || p.la_name() == "x") break;
		v.push_back(p);
	}
	for(Person p : v)
	{
		cout << p << "\n";
	}
}