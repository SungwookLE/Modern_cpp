#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	
	// move 생성자 권장 사항
	// => 되도록 예외가 발생하지 않도록 만들고 !
	// => 예외가 없다고 컴파일리에게 알려주세요. (+ noexcept)

	// noexcept 가 없다면,
	// 벡터 버퍼를 옮길 때, 예외가 발생하면 롤백이 되지 않으므로, Atomicity(원자성) 보장을 위해 복사 생성자가 불려짐
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // 복사 생성자
	Object o3 = std::move(o1); // move 생성자
	Object o4 = std::move_if_noexcept(o2);
				// Object 의 move 생성자가 예외가 없다면 move
				// 예외 가능성이 있다면 (noexcpet를 붙이지 않았다면) 복사



	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10); // 이 순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

