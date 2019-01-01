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

unsigned int Mult5 (unsigned int valor)
{
    valor = valor + valor + valor + valor + valor;
    return valor;
}

int main ()
{
    std::vector<unsigned int> random_num;
    random_num = RellenarVector (10000);

    unsigned int x;

    auto start = std::chrono::steady_clock::now();
    for (unsigned int i = 0; i < 10000; i++)
    {
        x = Mult5(random_num[i]);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end-start;

    std::cout << "La función propia ha tardado: " << diff.count() << " s\n";

    start = std::chrono::steady_clock::now();
    for (unsigned int i = 0; i < 10000; i++)
    {
        x = random_num[i] * 5;
    }
    end = std::chrono::steady_clock::now();
    diff = end-start;

    std::cout << "x*5 ha tardado: " << diff.count() << " s\n";

    return x;

}

