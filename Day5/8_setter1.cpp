// 105 page.. 상수 객체와 move
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept  {std::cout << "move" << std::endl;	}
};
int main()
{
	Object o1;
	Object o2 = std::move(o1);	// ??

    // 핵심. 상수객체는 move 될 수 없습니다.
	const Object o3;
	Object o4 = std::move(o3); // ??
                // static_cast<O3타입&&>(o3)
                // static_Cast<const Object&&>(o3)
}


