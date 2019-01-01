#include <iostream>
using namespace std;

template<int B>
constexpr int BinaryToDecimal() {
	return (BinaryToDecimal<B/10>() << 1) + (B % 10);
};

template<>
constexpr int BinaryToDecimal<0> () {
	return 0;
};

//Con constexpr. Sin template
/*constexpr int BinaryToDecimal(int B) {
return (B == 0) ? 0 : (BinaryToDecimal(B/10) << 1) + (B % 10);
}*/


int main()
{

	//Con constexpr. Con template
	cout << BinaryToDecimal<1101>() << endl; //13
	cout << BinaryToDecimal<1100>() << endl; //12
	cout << BinaryToDecimal<1111>() << endl; //15

	//Con constexpr. Sin template
	//cout << BinaryToDecimal(1101) << endl; //13

	return 0;
}