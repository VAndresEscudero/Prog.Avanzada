#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
#include <cstdlib>
#include <vector>

std::vector<unsigned int>  RellenarVector (unsigned int size)
{
    std::vector<unsigned int> vector_random;
    std::srand(std::time(0));

    for (unsigned int i = 0; i < size; i++)
    {

        unsigned int random_number = std::rand();
        vector_random.push_back(random_number);
    }

    return vector_random;
}

//Ordenadas de menos a mas eficiente

bool DivOcho (unsigned int num)
{
    bool is_div = false;

    if (num % 8 == 0)
        is_div = true;

    return is_div;
}

bool DivOcho01 (unsigned int num)
{
    bool is_div = false;

    num = num & 0x7;

    if (num == 0)
        is_div = true;

    return is_div;
}

inline bool DivOcho02 (unsigned int num)
{
    return ((num & 0x7) == 0 ? true : false);
}

//No cambia mucho respecto a la anterior
inline bool DivOcho03 (unsigned int num)
{
    const bool lookup[8] {true, false, false, false, false, false, false, false};
    num = num & 0x7;
    return (lookup[num]);
}

int main ()
{
    std::vector<unsigned int> random_num;
    random_num = RellenarVector (1000);

    auto start = std::chrono::steady_clock::now();
    for (unsigned int i = 0; i < 100; i++)
    {
        DivOcho(random_num[i]);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end-start;

    std::cout << "La función 0 ha tardado: " << diff.count() << " s\n";

    start = std::chrono::steady_clock::now();
    for (unsigned int i = 0; i < 100; i++)
    {
        DivOcho01(random_num[i]);
    }
    end = std::chrono::steady_clock::now();
    diff = end-start;

    std::cout << "La función 1 ha tardado: " << diff.count() << " s\n";

    start = std::chrono::steady_clock::now();
    for (unsigned int i = 0; i < 100; i++)
    {
        DivOcho02(random_num[i]);
    }
    end = std::chrono::steady_clock::now();
    diff = end-start;

    std::cout << "La función 2 ha tardado: " << diff.count() << " s\n";

    start = std::chrono::steady_clock::now();
    for (unsigned int i = 0; i < 100; i++)
    {
        DivOcho03(random_num[i]);
    }
    end = std::chrono::steady_clock::now();
    diff = end-start;

    std::cout << "La función 2 ha tardado: " << diff.count() << " s\n";

    return 0;
    
}
