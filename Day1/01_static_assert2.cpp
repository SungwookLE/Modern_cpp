#include <iostream>
#include <type_traits> 
#include <cstring>

#pragma pack(1) // 구조체 멤버 정렬을 1byte 단위로

struct PACKET
{
	char cmd;
	int  data;
};

static_assert(sizeof(PACKET) == sizeof(char)+ sizeof(int), "error, unexpected padding");

// int main()
// {
// 	std::cout << sizeof(PACKET) << std::endl; // ?
// }


template<typename T> void object_set_zero(T* p)
{
	// std::is_polymorphic<T>::value : T 타입이 가상함수가 있으면 true

	static_assert(!std::is_polymorphic<T>::value, "error T had virtual function");
	memset(p, 0, sizeof(T)); // ������ �ڵ� �ϱ�� ?
}

class A{
	int data;
	public:
	virtual int gg(int a){
		return 0;
	}
};

int main(){
	A a;
	object_set_zero(&a);

	return 0;
}