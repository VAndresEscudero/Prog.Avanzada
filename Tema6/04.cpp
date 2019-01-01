#include <iostream>
#include <stack>
using namespace std;

template <typename T>
unsigned g_contar (stack<T> s, T elem, unsigned w)
{
	unsigned e;
	
	if (s.empty())
		e = w;
	
	else
	{
		if (s.top() == elem)
		{
			s.pop();
			e = g_contar (s, elem, w+1);
		}
		else
		{
			s.pop();
			e = g_contar (s, elem, w);
		}
	}
	
	return e;
}

template <typename T>
unsigned contar2 (stack<T> s, T elem)
{
	return g_contar (s, elem, 0);
}

template <typename T>
unsigned contar3 (stack<T> s, T elem)
{
	unsigned w = 0;
	
	while (!s.empty())
	{
		if (s.top() == elem)
			++w;
		s.pop();
	}
	
	return w;
}

int main () 
{
	stack<unsigned> s;
	s.push(2); s.push(4); s.push(2); s.push(2); s.push(4); s.push(2); s.push(6); s.push(2);
	
	cout << g_contar(s, 2U, 0U) << endl; //5
	cout << g_contar(s, 4U, 0U) << endl; //2
	
	cout << endl;
	
	cout << contar2(s, 2U) << endl; //5
	cout << contar2(s, 4U) << endl; //2
	
	cout << endl;
	
	cout << contar3(s, 2U) << endl;
	cout << contar3(s, 4U) << endl;
	
	return 0;
}