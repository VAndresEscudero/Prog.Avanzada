#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector (const vector<T> & inputVector)
{
   for (T var : inputVector)
    cout << var << endl;
}

int main ()
{
    vector<int> v {1, 2, 3, 4, 5, 1000, -15};

    printVector (v);
    
    return 0;
}
