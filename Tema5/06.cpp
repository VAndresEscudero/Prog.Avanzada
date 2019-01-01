#include <iostream>
using namespace std;

template<int B>
class BinaryToDecimal {
public:
	static const int result = (BinaryToDecimal<B/10>::result << 1) + (B % 10);
};

template<>
class BinaryToDecimal<0> {
public:
	static const int result = 0;
};

int main()
{

	cout << BinaryToDecimal<1101>::result << endl; //13
	cout << BinaryToDecimal<1100>::result << endl; //12
	cout << BinaryToDecimal<1111>::result << endl; //15

	return 0;
}