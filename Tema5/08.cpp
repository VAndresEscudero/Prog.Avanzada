#include <iostream>
#include <vector>
using namespace std;

//typename iterator_traits<T>::value_type SumarContenedor (T first, T last)

template <unsigned DIM, typename T>
class SelfProduct {
public:
	static typename iterator_traits<T>::value_type result(T first) {
		return *first * SelfProduct<DIM - 1, T>::result(++first);
	}
};

template <typename T>
class SelfProduct<0,T> {
public:
	static typename iterator_traits<T>::value_type result(T last) {
		return *last;
	}
};

//Convenient function
template <unsigned DIM, typename T>
inline typename iterator_traits<T>::value_type self_product(T first)
{
	return SelfProduct<DIM, T>::result(first);
}

int main ()
{

	vector<int> v1{ 2,1,1,1,3 }; //6
	vector<double> v2{ 1.3, 2.4, 0.5, 6.7 };

	cout << self_product<4>(v1.cbegin()) << endl;
	cout << self_product<3>(v2.begin()) << endl;

	//Para este caso no puede deducir el segundo parametro del template hay que pasarselo explicitamente
	//cout << SelfProduct<unsigned(4), vector<int>::iterator>::result(v1.begin()) << endl;

	return 0;
}