#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template <typename T>
void printContainer (T inicio, T fin) {
    
   while (inicio != fin)
    {
        cout << *inicio << endl;
        ++inicio;
    }
}

int main ()
{
    vector<int> v {1, 2, 3, 4, 5, 1000, -15};
    list<string> l {"a", "bsf", "oigh4", "ldk34", "rgpi"};

    printContainer (v.begin(), v.end());
    printContainer (l.begin(), l.end());
    
    return 0;
}
