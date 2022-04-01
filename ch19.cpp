#include "iostream"
#include "string"
#include "vector"


template<typename T>
struct S
{
	explicit S(T v) : val{v}
	{}

	T& get();
	const T& get() const;

	/*void set(T va)
	{
		val = va;
	}*/

	S<T>& operator=(const T&);

private:
	T val;
};

template<typename T>
T& S<T>::get()
{
	return val;
};

template<typename T>
const T& S<T>::get() const
{
	return val;
};

template<typename T>
S<T>& S<T>::operator=(const T& v)
{
	val = v;
	return *this;
}

template<typename T>
void read_val(T& v)
{
	std::cin >> v;
}

/*template<typename T>
std::ostream& operator<<(std::ostream& o, S<std::vector<T>>& v)
{
	for(int i = 0; i < v.get().size(); i++)
	{
		o << v.get()[i] << " ";
	}
	o << "\n";
	return o;
}

template<typename T>
std::istream& operator>>(std::istream& i, S<std::vector<T>>& v)
{
	for(T a = 0; i >> a;)
	{
		if(a == 'x') break;
		else v.get().push_back(a);
	}
	return i;
} Nem olvastam végig a feladatot, emiatt nem felelnek meg neki, de ezek is működnek*/

template<typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T>& v)
{
	o << "{ ";
	for(int i = 0; i < v.size(); i++)
	{
		o << v[i] << " ";
	}
	o << "} \n";
	return o;
}

template<typename T>
std::istream& operator>>(std::istream& i, std::vector<T>& v)
{
	char c = ' ';
	int first = 0;
	i >> c;
	if(first == 0 && c!='{') 
	{
		std::cout << "missing {\n";
		return i;
	}
	first++;
	for(T a = 0; i >> a;)
	{
		if(a == '}') break;
		else v.push_back(a);
	}
	return i;
}

int main()
{

	S<int> si {1};
	S<char> ci {'a'};
	S<double> di {1.1};
	S<std::string> sti {"string"};
	S<std::vector<int>> vii {std::vector<int>{1,2,3, 5, 6, 7, 8}};
/*
	std::cout << si.val << "\n";
	std::cout << ci.val << "\n";
	std::cout << di.val << "\n";
	std::cout << sti.val << "\n";
	for(int i = 0; i < vii.val.size(); i++)
	{
		std::cout << vii.val[i] << " ";
	}
	std::cout  << "\n";
*/
	std::cout << si.get() << "\n";
	std::cout << ci.get() << "\n";
	std::cout << di.get() << "\n";
	std::cout << sti.get() << "\n";
	for(int i = 0; i < vii.get().size(); i++)
	{
		std::cout << vii.get()[i] << " ";
	}
	std::cout  << "\n";

	//si.set(3);
	si = 3;
	std::cout << si.get() << "\n";

	int i = 5;
	char c ='b';
	double d = 1.123;
	std::string s = "blabla";
	si = i;
	ci = c;
	di = d;
	sti = s;
	std::vector<int> vect;
	//std::cin >> vect;
	//std::cout << vect;
	read_val(vect);
	std::cout << vect;
	return 0;
}