// 11_rawstring
#include <iostream>
#include <string>

int main()
{

	// "\" : 특수 문자로 취급
	std::string s1 = "\\\\.\\pipe\\server";

	// raw string :  "\"를 특수 문자로 추기ㅡㅂ하지 말라
	// 시작 토큰: "(
	// 종료 토큰: )"
	std::string s2 = R"(\\.\pip\server)";
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	// 1. " 또는 ' 등을 표기하려면 => 그냥 표기하면 됩니다.
	std::string s3 = R"(\\.\pi"pe\server)";

	// 2. )" 를 표기하려면 어떻게 하나요?
	// => 시작과 끝을 사용자가 변경할 수 있습니다.
	// => 아래 코드는 "***( 가 시작 ) ***"가 종료
	std::string s4 = R"***(\\.\pi)"pe\server)***";



	
}