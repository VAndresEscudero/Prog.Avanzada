#include <iostream>
#include <vector>
using namespace std;

/*

CR: f(v,i) = f (v, ++i) * v[i];
	f1(v,i,w) = f(v,i) * w;
	f1 (vector<unsigned>, unsigned i, unsigned w)
	
CD: (i == v.size())
	f1 (v, v.size()) = 2 * w;
	
CR: (i < v.size())
	f1 (v,i,w) = f (v,i) * w = f (v, ++i)* v[i] * w =
	= f1 (v, ++i, w * v[i])
*/

unsigned f1 (vector<unsigned> v, unsigned i, unsigned w)
{
	
	unsigned e; //1
	
	if (i == v.size())
		e = w * 2;
	
	else
	{
		e = f1(v, ++i, w * v[i]);
	}
	
	return e;
}

unsigned f2 (vector<unsigned> v, unsigned i)
{
	return f1 (v, i, 1);
}

unsigned f3 (vector<unsigned> v, unsigned i)
{
	unsigned w = 1;
	
	while (i != v.size())
	{
		w *= v[i];
		++i;
	}
	
	w *= 2;
	
	return w;
}

int main () 
{
	vector<unsigned> v {1, 2, 3, 4, 5, 6};
	
	cout << f2(v, 6) << endl; //2
	cout << f2(v, 5) << endl;
	cout << f2(v, 4) << endl;
	cout << f2(v, 3) << endl;
	cout << f2(v, 2) << endl;
	cout << f2(v, 1) << endl;
	cout << f2(v, 0) << endl;
	
	cout << endl;
	
	cout << f3(v, 6) << endl; //2
	cout << f3(v, 5) << endl;
	cout << f3(v, 4) << endl;
	cout << f3(v, 3) << endl;
	cout << f3(v, 2) << endl;
	cout << f3(v, 1) << endl;
	cout << f3(v, 0) << endl;
	
	return 0;
}