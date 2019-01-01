#include <iostream>
#include <random>
#include <vector>
using namespace std;

template <typename T>
vector<T> crearRandom (T begin, T end)
{
    static_assert (is_integral<T>::value, "Solo valido para enteros");
    
    srand (time(0));

    vector<T> vec;

    T size = rand() % (end - begin) + begin;

    for (int i = 0; i < size; ++i)
        vec.push_back( rand() % (end - begin) + begin);
       
    return vec;
}

int main ()
{
    vector<int> v;

    v = crearRandom (50, 100);

    for (auto var : v)
        cout << var << endl;

    return 0;
}
