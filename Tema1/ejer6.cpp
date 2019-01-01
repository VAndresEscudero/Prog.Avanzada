#include <stdlib.h>
#include <random>
#include <list>
#include <vector>
#include <iostream>

std::vector<float> BucketSort (std::vector<float>, int, int);
int calculaBucket (int, float);

int main ()
{
    const int SIZE_VECTOR = 500;
    const int RANGO = 2000;
    const int OFFSET = -1000;

    std::vector<float> vectors;

    srand ( time(NULL) );
    
    float random_number;

    for (int i = 0; i < SIZE_VECTOR; i++)
    {
        random_number = ((float) rand()) / (float) RAND_MAX;
        random_number = (random_number * RANGO) + OFFSET;
        vectors.push_back(random_number);
    }

    vectors = BucketSort(vectors, RANGO, OFFSET);

    for (float f : vectors)
    {
        std::cout << f << std::endl;
    }

    return 0;
}

std::vector<float> BucketSort (std::vector<float> vector_num, int rango, int offset)
{
    int vector_tam = vector_num.size();

    std::list<float> bucket[vector_tam];

    for (int i = 0; i < vector_tam; i++)
    {
        int bucket_place = calculaBucket (vector_num[i]-offset, rango/float(vector_tam));
        bucket[bucket_place].push_back(vector_num[i]);
    }
    
    std::vector<float> resultado;

    for (int i = 0; i < vector_tam; i++)
    {
        bucket[i].sort();
        
        resultado.insert(std::end(resultado), std::begin(bucket[i]), std::end(bucket[i]));
    }

    return resultado;
    
}

int calculaBucket (int x, float incrementos)
{
    return (float(x)/incrementos);
}
