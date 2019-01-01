#include <iostream>
using namespace std;

template <typename T>
long sizeof_bits (const T & objeto)
{
    return (8 * sizeof(objeto));
}

int main ()
{
    cout << sizeof_bits (long (3)) << endl;
    cout << sizeof_bits (float (3.8)) << endl;
    cout << sizeof_bits (char (1)) << endl;
}
