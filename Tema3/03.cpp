#include <iostream>
#include <climits>
using namespace std;

unsigned long ContarUnos (unsigned long numero)
{   
    unsigned long cantidad = 0;
    unsigned int aux, aux2, aux3, aux4;
    
    for (unsigned long i = 0; i < CHAR_BIT * sizeof numero; ++i, numero >>= 4)
    {
        aux = numero & 1;
        aux2 = (numero >> 1) & 1;
        aux3 = (numero >> 2) & 1;
        aux4 = (numero >> 3) & 1;

        aux = aux + aux2 + aux3 + aux4;
        cantidad += aux;
    }

    return cantidad;
}


int main ()
{
    unsigned long num_unos = ContarUnos (4095);
    unsigned long num_unos1 = ContarUnos (23754421);
    cout << num_unos << endl;
    cout << num_unos1 << endl;
    return 0;
}

