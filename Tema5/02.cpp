#include <iostream>
#include <type_traits>
using namespace std;


template <typename T>
class Complejo {
	public:
		T real;
		T imaginario;
		Complejo(T real, T imaginario)
		{
			this.real = real;
			this.imaginario = imaginario;
		}
};

template <typename T>
struct is_complex
{
	static bool const value = false;
};

template <typename T>
struct is_complex<Complejo<T>>
{
	static bool const value = true;
};

template<typename T>
struct is_complex_and_floating
{
	static bool const value = false;
};

template <typename T>
struct is_complex_and_floating<Complejo<T>>
{
	static bool const value = is_floating_point<T>::value;
};


int main()
{
	
	cout << boolalpha;
	cout << is_complex<Complejo<float>>::value << endl; //true
	cout << is_complex_and_floating<Complejo<int>>::value << endl; //false
	cout << is_complex_and_floating<Complejo<double>>::value << endl; //true
	cout << is_complex_and_floating<float>::value << endl; // false

	return 0;
}