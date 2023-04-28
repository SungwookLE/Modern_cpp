#include <iostream>

// T 가 포인터 인지 조사하는 기술

// type traits : 템플릿 인자 T의 타입에 대한 정보를 조사하는 기술
// => 컴파일 시간에 동작
// 		ㄴ enum(mon=1, tue = 2}; ==> enum "상수" 는 컴파일하고 나면,,int n = mon ===> int n = 1 로 치환되서 바뀜
// => "메타 함수"라는 용어도 사용됩니다.
// => 주로 부분 특수화 기술로 만들게 됩니다. 

// 핵심 1. primary template 을 만들고 false 반환 (value =false 라는 의미)
template<typename T> struct is_pointer{
	// 왜 enum 을 사용하나요?
	// bool value = false ; // 이렇게 하면
						// 1. 컴파일 시간 상수가 아닌 "변수"!
						// 2. C+11 이전에는 여기서 초기화 안됨

	// 매크로는 안되나요?
	// 매크로 : 컴파일 전에 전처리가 이미 처리
	//		   전처리된 후에는 컴파일러는 알지 못하는 기호가 됩니다.
	
	enum {value = false}; // enum hack 이라고 합니다.

	// 그런데, 이 C+11 부터는 enum 대신 아래처럼 하면 됩니다.
	// static constexpr bool value = false;
};

// 핵심 2. 조건을 만족하는 부분 특수화 버전을 만들고 true 반환 (value=true)
template<typename T> struct is_pointer<T*>{
	// enum {value = true};
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	// 현재 T 는 int, int*
	if ( is_pointer<T>::value )
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}