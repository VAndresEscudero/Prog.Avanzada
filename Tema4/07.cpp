#include <iostream>
#include <random>
#include <array>
#include <vector>
#include <list>
using namespace std;

template <typename T>
T crearRandom (int begin, int end)
{   
    srand (time(0));

    T contenedor;

    int size = rand() % (end - begin) + begin;

    for (int i = 0; i < size; ++i)
        contenedor.push_back( rand() % (end - begin) + begin);
       
    return contenedor;
}

int main ()
{
    auto v = crearRandom<vector<int>> (2, 10);
    auto l = crearRandom<list<int>> (2,10);

    cout << "vector" << endl;
    for (auto var : v)
        cout << var << endl;

    cout << "lista" << endl;
    for (auto var : l)
        cout << var << endl;

    return 0;
}
