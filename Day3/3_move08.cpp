#include <iostream>
#include <string>

// 자동 생성 규칙.

// 규칙1. 사용자가 복사 계열(생성자와 대입연산자)과 move 계열의 모든 함수를 제공하지 않을 때
// 	=> 컴파일러가 모두 자동생성해 준다.
// 	=> 자동생성된 복사 계열 함수: 모든 멤버를 복사 해준다.
// 	=> 자동생성된 이동 계열 함수: 모든 멤버를 이동(std::move()) 해준다.


// 규칙2. 사용자가 복사 계열만 제공할 때
// => 컴파일러는 move 계열 함수를 자동생성하지 않음
// => std::move() 사용시 사용자가 만든 복사 계열 함수를 사용하게 됨
// => 컴파일러에게 move 계열 함수의 디폴트 버전을 요청하려면, "=default"사용


// 규칙3. 사용자가 move 계열만 제공한 경우
// => 컴파일러는 복사 계열을 "삭제" 합니다.
// => 이동이 필요할 때 복사를 사용할 수 있지만, 복사가 필요할 때 이동을 사용할수는 없으므로
// => 복사 생성자가 필요한 코드를 사용하는 경우 컴파일 에러
// => 이 경우도 복사 계열을 "=default"로 요청 가능합니다.


struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {} // 생성자

	/*
	Object(const Object& obj): name(obj.name){
		std::cout << "사용자가 만든 복사 생성자" << std::endl;
	}

	// 위에 복사 생성자를 만들었지만, 나머지 함수는 컴파일러의 디폴트 버전을 사용하려면 아래처럼 요청합니다.
	Object(Object&&) = default;
	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;
	*/

	Object(Object&& obj): name(std::move(obj.name)){
		std::cout << "사용자가 만든 이동 생성자" << std::endl;
	}

};

int main()
{
	Object o1("obj1 to be or not to be");
	Object o2("obj2 to be or not to be");

	Object o3 = o1;
	Object o4 = std::move(o2); // 사용자가 복사생성자를 정의하였는데, move 생성자가 따로 없으므로 복사 생성자가 호출됨

	std::cout << o1.name << std::endl;
	std::cout << o2.name << std::endl; // ""
}