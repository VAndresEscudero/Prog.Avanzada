#include <iostream>
#include <array>

using namespace std;

template <class T, size_t tam>
int suma (array<T,tam> a)
{
    T resultado = 0.0;

    for (unsigned i = 0; i < a.size(); i++)
    {
        resultado += a[i];
    }
    
    return resultado;
}

int main ()
{
    array<int,5> a = {2,4,6,8,10}; 
    int s = suma(a); 
    cout << s << endl; 
}


