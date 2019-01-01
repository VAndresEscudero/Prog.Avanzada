#include <utility>
#include <iostream>


class Pila 
{ 
    unsigned max_tam;
    int * v;
    int cima;
    public:
        Pila(unsigned tam)
        {
            v = new int[tam];
            max_tam = tam;
            cima = -1; 
        }
        
        Pila (Pila &&p)
        {
            cima = p.cima;
            max_tam = p.max_tam;
            v = p.v;
            p.v = nullptr;
        }
        
        Pila & operator= (Pila &&p)
        {
            delete v;
            cima = p.cima;
            max_tam = p.max_tam;
            v = p.v;
            p.v = nullptr;
            return *this;
        }
};

int main ()
{
    Pila p1(5);
    Pila p2(5);

    p2 = std::move(p1);

    //std::cout << p1.v << "\n";

    return 0;
} 
