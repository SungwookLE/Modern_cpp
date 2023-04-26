// 3_�Լ���ü7 - 136 page�ҽ�
#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less { inline bool operator()(int a, int b) { return a < b; } };
struct Greater { inline bool operator()(int a, int b) { return a > b; } };

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// C++ ǥ�� sort()�� ��� ���ڰ� ���ø� �Դϴ�.
	// => ����ڰ� ����ϴ� �ڵ带 ���� ���� sort �Լ��� �����ȴٴ� �ǹ�

	// 1. �� ��å���� �Ϲ��Լ� ����

	std::sort(x, x + 10, cmp1); 
	std::sort(x, x + 10, cmp2); 

	// 2. ����å���� �Լ���ü ����

	Less    f1;
	Greater f2;
	std::sort(x, x + 10, f1); 
	std::sort(x, x + 10, f2); 
}









