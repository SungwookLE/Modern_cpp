#include <iostream>
using namespace std;
// 160 page
template<typename T, typename U> struct Object
{
	static void foo() { cout << "T, U" << endl; }
};

int main()
{
	// 아래 처럼 나오게 만들어 보세요.
	Object<int,  double >::foo();// T, U
	Object<int*, double*>::foo();// T*, U*
	Object<int*, double> ::foo();// T*, U
	Object<int,  int>::foo();    // T, T
	Object<int, short>::foo();   // int, short
}

