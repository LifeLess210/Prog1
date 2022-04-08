#include "std_lib_facilities.h"

//átneveztem mycopy-ra mert overloadolt
//f1-től e1-ig mindent másol f2-től kezdve f2+(e1-f1) elemig
template<typename Iter1, typename Iter2>
Iter2 mycopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for(Iter1 p = f1; p != e1; p++)
	{
		*f2 = *p;
		f2++;
	}
	return f2;
}


int main()
{
	array<int, 10> a{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	array<int, 10> a2 = a;
	vector<int> v2 = v;
	list<int> l2 = l;

	//növelések
	for(auto& i : a)
	{
		i = i+2;
	}
	for(auto& i : v)
	{
		i = i+3;
	}
	for(auto& i : l)
	{
		i = i+5;
	}

	mycopy(a.begin(), a.end(), v.begin());
	mycopy(l.begin(), l.end(), a.begin());

	int n = 3;
	auto it = find(v.begin(), v.end(), n);
	if(*it != *v.end()) cout << "Position of " << n << ": " << *it << "\n";
	else cout << "value was not found\n";

	n = 27;
	auto it2 = find(l.begin(), l.end(), n);
	if(*it2 != *l.end()) cout << "Position of " << n << ": " << *it2 << "\n";
	else cout << "value was not found\n";
}