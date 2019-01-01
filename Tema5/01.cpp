#include <tuple>
#include <iostream>
using namespace std;

template <typename T, typename T2>
tuple<T, T2> dividir(T dividendo, T2 divisor)
{
	return{ int(dividendo / divisor), dividendo % divisor };
}


int main()
{
	int int1 = 10;
	int int2 = 3;

	unsigned unsigned1 = 4;

	auto t = dividir(int1, int2);
	cout << get<0>(t) << " " << get<1>(t) << endl;

	t = dividir(int1, unsigned1);
	cout << get<0>(t) << " " << get<1>(t) << endl;

	return 0;
}