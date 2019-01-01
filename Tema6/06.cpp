#include <iostream>
#include <array>
#include <cmath>
using namespace std;

unsigned const TAM = 5;

array<array<bool, TAM>, TAM> Warshall (array<array<float, TAM>, TAM> & matriz)
{
	array<array<bool, TAM>, TAM> solucion;
	
	//k = 0
	for (unsigned i = 0; i < matriz.size(); ++i)
	{
		for (unsigned j = 0; j < matriz[0].size(); ++j)
		{
			solucion[i][j] = INFINITY > matriz[i][j];
		}
	}
	
	for (unsigned k = 1; k < matriz.size(); ++k)
	{
		for (unsigned i = 0; i < matriz.size(); ++i)
		{
			for (unsigned j = 0; j < matriz[0].size(); ++j)
			{
				solucion[i][j] = solucion[i][j]  || ((INFINITY > matriz[i][k]) &&  (INFINITY > matriz[k][j]));
			}
		}
	}
	
	return solucion;
}

int main ()
{
	array<array<bool, TAM>, TAM> output;
	
	array<array<float, TAM>, TAM> input;
	
	//Ejemplo de clase.
	input[0][0] = 0;
	input[1][0] = INFINITY;
	input[2][0] = INFINITY;
	input[3][0] = INFINITY;
	input[4][0] = INFINITY;
	
	input[0][1] = 3;
	input[1][1] = 0;
	input[2][1] = INFINITY;//
	input[3][1] = 1;
	input[4][1] = 0;
	
	input[0][2] = INFINITY;//
	input[1][2] = 1;
	input[2][2] = 0;
	input[3][2] = 2;
	input[4][2] = 2147483647;//
	
	input[0][3] = 1;
	input[1][3] = INFINITY;//
	input[2][3] = 3;
	input[3][3] = 0;
	input[4][3] = 6;
	
	input[0][4] = 5;
	input[1][4] = INFINITY;//
	input[2][4] = 4;
	input[3][4] = INFINITY;//
	input[4][4] = 0;
	
	output = Warshall (input);
	cout << boolalpha;
	
	for (unsigned i = 0; i < TAM; ++i)
	{
		for (unsigned j = 0; j < TAM; ++j)
			cout << output[i][j] << "\t";
		cout << endl;
	}
			
	
	return 0;
}