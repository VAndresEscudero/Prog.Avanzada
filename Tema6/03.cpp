#include <iostream>
using namespace std;

unsigned g_elev (unsigned a, unsigned b, unsigned w)
{
	unsigned e;
	
	if (b == 0)
		e = w;
	
	else
		e = g_elev (a, b-1, a*w);
	
	return e;
}

unsigned elev (unsigned a, unsigned b)
{
	return g_elev(a, b, 1);
}

unsigned elev3 (unsigned a, unsigned b)
{
	unsigned w = 1;
	
	while (b != 0)
	{
		w *= a;
		--b;
	}
	
	return w;
	
}

int main ()
{
	cout << elev(3,2) << endl; //9
	cout << elev(3,3) << endl; //27
	cout << elev(5,3) << endl; //125
	
	cout << endl;
	
	cout << elev3(3,2) << endl; //9
	cout << elev3(3,3) << endl; //27
	cout << elev3(5,3) << endl; //125
	
	return 0;
}