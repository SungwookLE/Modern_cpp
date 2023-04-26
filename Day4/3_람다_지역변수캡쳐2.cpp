// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	auto f2 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 


}





