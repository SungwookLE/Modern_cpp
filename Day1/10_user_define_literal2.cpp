// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 

using namespace std::literals; // 표준이 제공하는 리터럴 접미사

void foo(const char* s) { std::cout << "const char*\n"; }
void foo(std::string s) { std::cout << "string\n"; }

int main()
{
	foo("hello");  // const char* 를 호출할 것임
	foo("hello"s); // string
				   // operator ""s("hello")의 반환 타입이 string
				   // 정수형 리터럴 접미사 인자는 unsigned long long
				   // 문자열 리터럴은 const char*
	
	auto s1 = "hello";
	auto s2 = "hello"s;

	std::chrono::seconds s3(3); //3초
	auto s4 = 3s;	// 위와 동일

	std::chrono::seconds s5 = 1h+3min+20s;
	std::cout << s5.count() << std::endl;

	// RUST 코드
	// let n1 = 10_i32; // i32 타입의 리터럴 10/
	// let n2 = 10_u32; // u32(unsigned int 32bit)
}


