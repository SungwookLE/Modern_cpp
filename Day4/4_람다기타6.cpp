#include <functional>

template<typename T>
void f1(T f){}


template<typename T>
void f2(T&& f){}

int main(){

	std::less<int> f;

	// 아래 4줄을 깊이 있게 생각해보세요.
	// f1, f2는 각각 함수가 몇개 생성되었을까요?  f1은 시그니쳐가 한개니까 1개 생성, f2는 lvalue, rvalue 에 대한 시그니처 각각 1개씩 2개

	f1(f);
	f1(std::less<int>());
	f2(f);
	f2(std::less<int>());
}