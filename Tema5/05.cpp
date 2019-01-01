#include <iostream>
#include <vector>
#include <list>
#include <math.h>
using namespace std;

class HarmonicMean {
public:
	template<typename T>
	static void accumulate (double & total, T const & value)
	{
		total += 1./value;
	}

	static void media(double & total, unsigned value)
	{
		--total; //Ya que empieza en 1 antes
		total = value / total;
	}
};

class AritmeticMean {
public:
	template<typename T>
	static void accumulate(double & total, T const & value)
	{
		total += value;
	}

	static void media(double & total, unsigned value)
	{
		--total; //Ya que empieza en 1 antes
		total /= value;
	}
};

class GeometricMean {
public:
	template<typename T>
	static void accumulate(double & total, T const & value)
	{
		total *= value;
	}

	static void media(double & total, unsigned value)
	{
		total = pow(total, 1. / value);
	}
};

template <typename Policy = AritmeticMean, typename T>
auto SumarContenedor(T first, T last)
{
	double total = double ();
	++total;

	unsigned iteraciones = 0;

	while (first != last)
	{
		Policy::accumulate(total, *first);
		++first;
		++iteraciones;
	}

	Policy::media(total, iteraciones);

	return total;
}

int main()
{
	vector<float> v1 {1.5f, 3.2f, 4.7f};
	vector<unsigned> v2 {1, 2, 8};

	cout << "Aritmetica" << endl;
	cout << SumarContenedor<AritmeticMean>(v1.begin(), v1.end()) << endl;
	cout << SumarContenedor<AritmeticMean>(v2.begin(), v2.end()) << endl << endl;

	cout << "Geometrica" << endl;
	cout << SumarContenedor<GeometricMean>(v1.begin(), v1.end()) << endl;
	cout << SumarContenedor<GeometricMean>(v2.begin(), v2.end()) << endl << endl;

	cout << "Harmonica" << endl;
	cout << SumarContenedor<HarmonicMean>(v1.begin(), v1.end()) << endl;
	cout << SumarContenedor<HarmonicMean>(v2.begin(), v2.end()) << endl;

	return 0;
}