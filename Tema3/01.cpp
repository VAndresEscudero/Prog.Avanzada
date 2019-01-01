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

bool IsEven (unsigned int num)
{
    bool is_even = false;

    if (num % 2 == 0)
        is_even = true;

    return is_even;
}

bool IsEven01 (unsigned int num)
{
    bool is_even = false;

    num = num & 0x1;

    if (num == 0)
        is_even = true;

    return is_even;
}

inline bool IsEven02 (unsigned int num)
{
    return ((num & 0x1) == 0 ? true : false);
}

//Tarta casi lo mismo que antes
inline bool IsEven03 (unsigned int num)
{
    const bool lookup[2] {true, false};

    num = num & 0x1;

    return lookup[num];
}
    

int main ()
{
    std::vector<unsigned int> random_num;
    random_num = RellenarVector (10000);

    auto start = std::chrono::steady_clock::now();
    for (unsigned int i = 0; i < 10000; i++)
    {
        IsEven(random_num[i]);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end-start;

    std::cout << "La función 0 ha tardado: " << diff.count() << " s\n";

    start = std::chrono::steady_clock::now();
    for (unsigned int i = 0; i < 10000; i++)
    {
        IsEven01(random_num[i]);
    }
    end = std::chrono::steady_clock::now();
    diff = end-start;

    std::cout << "La función 1 ha tardado: " << diff.count() << " s\n";

    start = std::chrono::steady_clock::now();
    for (unsigned int i = 0; i < 10000; i++)
    {
        IsEven02(random_num[i]);
    }
    end = std::chrono::steady_clock::now();
    diff = end-start;

    std::cout << "La función 2 ha tardado: " << diff.count() << " s\n";

    start = std::chrono::steady_clock::now();
    for (unsigned int i = 0; i < 10000; i++)
    {
        IsEven03(random_num[i]);
    }
    end = std::chrono::steady_clock::now();
    diff = end-start;

    std::cout << "La función 3 ha tardado: " << diff.count() << " s\n";

    return 0;
    
}
