#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    vector<int> c = {1,2,3};
    auto mult3 = [](int &n) {n = n*3;};
    for_each(c.begin(), c.end(), mult3);

    for (auto a : c)
    {
        cout << a << "\n";
    }

    return 0;
}
