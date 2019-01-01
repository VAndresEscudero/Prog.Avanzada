#include <iostream>
#include <vector>
#include <forward_list>
using namespace std;

template <typename T>
//typename iterator_traits<T>::value_type SumarContenedor (T first, T last)
auto SumarContenedor(T first, T last)
{
	iterator_traits<T>::value_type total = 0;

	while (first != last)
	{
		total += *first;
		++first;
	}

	return total;
}

int main ()
{
	vector<int> v{ 1,3,4,6,8,-12,23 };
	forward_list<double> f{ 1,2,3,4,5.5,6,7,8,9,-10.123 };

	cout << SumarContenedor(v.begin(), v.end()) << endl; //33
	cout << SumarContenedor(f.begin(), f.end()) << endl;

	return 0;
}