#include <iostream>
#include <list>
#include <forward_list>
using namespace std;



int main ()
{

    list<int> l1 = {1,2,3};
    list<int> l2 = {-2, -1};

    //Insertar 0 al principio de l1
    l1.push_front(0);

    //Insertar 4 al final de l1
    l1.push_back(4);

    //Insertar l2 al principio de l1
    l1.insert(l1.begin(), l2.begin(), l2.end());
    
    //Imprime por pantalla
    for (auto num : l1)
        cout << num << "    ";
    cout << "\n";

    forward_list<int> l3 = {1,2,3}; 
    forward_list<int> l4 = {-2, -1};

    //Insertar 0 al principio de l3
    l3.push_front(0);

    //Insertar 4 al final de l3
    auto puntero = l3.before_begin();
    auto puntero_ant = puntero;
    puntero++;
    while (puntero != l3.end())
    {
        puntero++;
        puntero_ant++;
    }
    l3.insert_after(puntero_ant, 4);


    //Insertar l4 al principio de l3
    auto nuevo_puntero = l3.before_begin();
    for (auto num : l4)
    {
        if (nuevo_puntero == l3.before_begin())
        {
            l3.push_front(num);
        }
        else
            l3.insert_after(nuevo_puntero, num);
        nuevo_puntero++;
    }
    
    //Imprimer por pantalla
    for (auto num : l3)
            cout << num << "    ";
        cout << "\n";

    return 0;
}
