#include <iostream>
using namespace std;

unsigned cuantosArgumentos () { return 0; }

template <typename T, typename... Args>
unsigned cuantosArgumentos (T primero, Args... args)
{
    return 1 + cuantosArgumentos (args...);
}
    

int main ()
{
    
    cout << cuantosArgumentos (1, 2, 3, 4, 5, 6, 7, 8) << endl;
    return 0;
}
