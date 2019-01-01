#include <utility>
#include <iostream>


class Pila 
{ 
    public:
        unsigned max_tam;
        int cima;
        int * v;

        Pila(unsigned tam)
        {
            v = new int[tam];
            max_tam = tam;
            cima = -1; 
        }
        
        Pila (std::initializer_list<int> l)
        {
            cima = l.size() - 1;
            max_tam = l.size();
            v = new int[max_tam];

            for (unsigned i = 0; i < l.size(); i++)
            {
                //En la dir. de memoria de v[0] meter el valor de l.begin() + i
                v[i] = *(l.begin() + i);
            }
        }
        
        
};

int main ()
{
    Pila p1({1,2,3,5});

    for (unsigned i = 0; i < p1.max_tam; i++)
        std::cout << *(p1.v + i) << "\n";

    /*for (int i : p1)
        std::cout << i << "\n";*/

    return 0;
} 
