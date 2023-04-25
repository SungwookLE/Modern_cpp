#include <iostream>
#include <type_traits>


// lvalue 인지 rvalue인지 조사하는 방법
// 원리: decltype(exp) = exp 가 lvalue 라면 참조 타임

// int main(){
// 	int n = 0;
// 	(n=20)=10;

// 	using exp_type = decltype(n);
// 	if(std::is_lvalue_reference<decltype(n=20)>::value)			
// 		std::cout << "lvalue" << std::endl;								
// 	else																	
// 		std::cout << "rvalue" << std::endl;	

	
// 	return 0;
// }

// () 를 덧대줌으로써 규칙2 사용 즉 연산의 결과가 lvalue가 될 수 있느냐로 판단
#define CHECK_VALUE_CATEGORY( ... )										\
if(std::is_lvalue_reference<decltype((__VA_ARGS__))>::value)			\ 	
		std::cout << "lvalue" << std::endl;								\
else																	\
	std::cout << "rvalue" << std::endl;	


int main(){

	int n = 10;
	CHECK_VALUE_CATEGORY(n); 	// lvalue
	CHECK_VALUE_CATEGORY(3);	// rvalue
	CHECK_VALUE_CATEGORY(++n);	// lvalue
	CHECK_VALUE_CATEGORY(n++);	// rvalue
	CHECK_VALUE_CATEGORY(n+n); 	// rvalue
	CHECK_VALUE_CATEGORY(n+20); // rvalue

	CHECK_VALUE_CATEGORY("hello"); // lvalue, 핵심 놀라운 결과

}