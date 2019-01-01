#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main ()
{
    vector<list<double>> v;

    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << "\n";
        }
    }

    return 0;
}
