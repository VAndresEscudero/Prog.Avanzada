#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


inline float MyPow (float x, unsigned exp)
{
    float resultado = 1;
    
    /*Pow es una funcion pensada para exponentes altos.
      Para exponentes bajos es más eficiente multiplicar por "fuerza bruta"
      El valor exacto a partir del cual no vale la pena depende. 
      En mi caso el tiempo no varia mucho a partir de 50.*/
    if (exp < 80)
    {
        for (unsigned i = 0; i < exp; i++)
        {
            resultado *= x;
        }
    }
    else
        resultado = pow(x, exp);

    return resultado;
}

float eval(const vector<float> &a, float x)
{ 
    float y;
    y = a[0];

    for(unsigned i = 1; i < a.size(); ++i)
        y += a[i] * MyPow(x,i);

    return y;
}

int main ()
{

    srand(time(0));
    vector<vector<float>> vec_de_vec;
    
    for (int i = 0; i < 1000000; ++i) //1,000,000 ecuaciones a calcular
    {
        vector<float> aux;

        int number_1_100 = rand() % 100 + 1; //Numero entre 1 y 100

        for (int j = 0; j < number_1_100; j++) //Con 1-100 cocientes
        {
            aux.push_back(rand() % 100 + 1); //Con valores entre 1 y 100
        }
        
        vec_de_vec.push_back(aux);
    }

    for (int i = 0; i < 1000000; ++i)
    {
        eval(vec_de_vec[i], rand() % 10000); //x entre 0 y 10000
    }

    return 0;
}
