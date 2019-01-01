#include <iostream>
using namespace std;

template <typename T, typename T2>
T resta (T primero, T2 segundo)
{
    static_assert (is_arithmetic<T>::value && is_arithmetic<T2>::value, "Algun parametro no es un numero");
    return primero - segundo;
}



int main () {

    int foo = 120;
    long bar = 121;
    string s = "hola";

    cout << resta(foo, bar) << endl;

    //cout << resta(foo, s) << endl;
    return 0;
}
