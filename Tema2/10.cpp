#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

unordered_map<string, int> cuantosStrings (vector<string> vec_strings)
{
    unordered_map<string, int> hash;

    //Introducimos en el hash
    for (unsigned i = 0; i < vec_strings.size(); i++)
    {
        ++hash[vec_strings[i]];
    }

    for (const auto& caso : hash) {
        std::cout << caso.first << " aparece " << caso.second << " veces.\n";
    }
        

    return hash;
}

int main ()
{

    vector<string> palabras = {"a", "b", "f", "g", "a", "b", "g", "h"};
    cuantosStrings(palabras);
    
    
    return 0;
}

