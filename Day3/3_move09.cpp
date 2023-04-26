// Rule Of 0

#include <iostream>
#include <cstring>



// 클래스 안에 사용자가 직접 자원을 관리하는 코드가 있다면
// => char*, int* 등을 멤버가 있고 동적할당하면 복사계열, 이동 계열을 모두 제공해야 합니다.

// 하지만, 자원을 자원을 직접 관리하는 코드가 없다면,
// => 복사와 이동 모두 만들지 마세요.
// => 컴파일러가 제공해 줍니다.

// 자원을 직접 관리하지 말고, 자원 관리 클래스를 사용하세요.
// => 문자열 필요: char* 사용하지 말고 string
// int* => 스마트 포인터 또는 std::vector 사용하세요.

// 사용자 정의 클래스를 만들때 멤버로 포인터가 있으면 복사생성자, 대입연산자, 이동생성자를 무조건 사용자가 정의해주어야한다. 
// 그렇지 않으면 컴파일러가 만들어주는데, shallow copy가 될 뿐더라, 무조건 복사연산만 되기 때문에 속도도 구림
class Cat
{
	// char* name; // 이런 예제에서는 포인터보다 그냥 스트링 쓰면 포인터 안써도되니까 좋음
    std::string name;
	int   age;
public:
	Cat(const char* n, int a) : age(a), name(n){}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;   					// 복사 생성자
	Cat c3 = std::move(c1);			// move 생성자

	c3 = c2;						// 대입 연산자 호출
	c3 = std::move(c2);				// move 이동 대입연산자 호출
}

