#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T, unsigned MAX = 50>
class Array2
{
    public: 
        T contenedor[MAX];
        T& operator [](unsigned i);
};

template <typename T, unsigned N>
T& Array2<T,N>::operator [](unsigned num)
{   
    if (num >= N)
        throw out_of_range("Out of bounds");

    return contenedor[num];
}

int main ()
{
    Array2<int> my_array;

    my_array[2] = 10;

    cout << my_array[2] << endl;

    cout << my_array[123] << endl;

    return 0;
}
