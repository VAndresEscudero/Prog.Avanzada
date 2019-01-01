#include <iostream>
using namespace std;

unsigned sumaTodos () {return 0;}

template <typename T, typename... Args>
unsigned sumaTodos (T primer, Args... args)
{
    return primer + sumaTodos (args...);
}
    

int main ()
{
    
    cout << sumaTodos (1, 2, 3, 4, 5, 6, 7, 8) << endl;
    return 0; 
}
