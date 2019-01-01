#include <iostream>
#include <vector>
using namespace std;

const unsigned TAM = 10;

template <unsigned MAX, typename T>
class vector_init {
public:
	static void inicializa(T* v, T x)
	{
		v[MAX] = x;
		vector_init<MAX - 1, T>::inicializa(v, x);
	}
};

template <typename T>
class vector_init<0,T> {
public:
	static void inicializa(T* v, T x)
	{
		v[0] = x;
	}
};


template <unsigned MAX, typename T>
inline void inicializa_func (T* v, T x)
{
	vector_init<MAX, T>::inicializa(v, x);
}


int main ()
{

	int array1[TAM];
	float array2[TAM];

	inicializa_func<TAM>(array1, 3);
	inicializa_func<TAM>(array2, 5.3f);

	for (unsigned i = 0; i < TAM; ++i)
	{
		cout << array1[i] << "  ";
	}

	cout << endl;

	for (unsigned i = 0; i < TAM; ++i)
	{
		cout << array2[i] << "  ";
	}

	cout << endl;

	return 0;
}