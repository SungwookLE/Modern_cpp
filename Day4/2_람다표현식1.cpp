// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort 하고 싶다면
	std::sort(v.begin(), v.end()); 

}





