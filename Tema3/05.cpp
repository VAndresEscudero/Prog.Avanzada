#include <vector>
#include <iostream>
using namespace std;

//Con time se consigue una mejora de unos 0.7s o del 30%.

// Return the position of the element. 
// Out of bound if the element doesn’t exist.
unsigned search_optimizado(vector<int> &v, int x) 
{ 
    unsigned pos = 0;
    v.push_back(x); //Añadir valor a buscar al final

    while(v[pos] != x) 
        ++pos;  //Usar ++pos en lugar de pos++

    v.pop_back(); //Quitamos el elemento

    return pos; 
}

// Return the position of the element. 
// Out of bound if the element doesn’t exist.
unsigned search(vector<int> &v, int x) 
{ 
  unsigned pos = 0; 
  while(pos < v.size() && v[pos] != x) 
    pos++; 
  return pos; 
} 

vector<int>  RellenarVector (unsigned int size);

int main ()
{
    vector<int> vec = RellenarVector (100000);
    srand(time(0));
    
    for (int i = 0; i < 100000; ++i)
    {
        int random_number = rand();
        //search_optimizado(vec, random_number);
        search(vec, random_number);
    }

    cout << "Con time se consigue una mejora de unos 0.7s o del 30%." << endl;

    return 0;
}



vector<int>  RellenarVector (unsigned int size)
{
    vector<int> vector_random;
    srand(time(0));

    for (unsigned int i = 0; i < size; i++)
    {

        int random_number = rand();
        vector_random.push_back(random_number);
    }

    return vector_random;
}

