#include <list>
#include <iostream>

// STL 에서 상속받는 것이 좋지는 않지만
// => 멤버 함수 1 ~ 2개 정도 추가하는 코드는 가끔 볼 수 있습니다.
class MyList : public std::list<int>
{
public:
	// 생성자 상속이 없다면 lists의 모든 생성자 모양을 동일하게 만들어야 합니다.
	// MyList(int sz, int value): std::list<int>(sz, value){}
	// MyList(int sz): std::list<int>(sz){}
	
	// 생성자 상속을 사용하면 한줄이면 됩니다.
	using std::list<int>::list;


	void dump(){}
};

int main()
{
	MyList st1(10, 3); // 10���� 3���� �ʱ�ȭ
	MyList st2(10);

}




