#include <iostream>
using namespace std;

class c {
  bool a; 
  float b; 
  unsigned short c; 
}; 


int main ()
{
    c v[10];
    cout << endl;
    cout << "Deberia de ocupar 12 bytes debido a la alineación. Bool ocupa 1 byte. ";
    cout << "Float ocupa 4 bytes pero por alineación deben de haber 3 bytes previos sin usar. ";
    cout << "Unsigned short ocupa 2 bytes. Para que la estructura este alineada se usan 2 bytes posteriores. En total 12 bytes por instancia, 5 bytes malastados. ";
    cout << "Modificando el orden de los atributos se podria almezenar en 8 bytes malgastando solo 1.";
    cout << endl;
    cout <<"Realizando sizeof... " << sizeof(v) << ". Hay 10 elementos." << endl << endl;

    return 0;
}

