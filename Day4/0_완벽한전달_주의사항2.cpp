template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}

void foo() {}
void foo(int a) {}
void foo(int a, int b) {}

int main()
{
	// 함수를 직접 호출시
	// => 인자를 보고 어느 함수인지 찾을 수 있다.
	foo();
	foo(10);
	foo(10, 20);
 
//	chronometry(foo, 10); // error. 어떤 foo인지 알수 없다...., 타입추론으로는 어떤 foo 인지 알수없어

	chronometry(static_cast<void(*)(int)>(foo), 10); // static_cast 해서 함수의 프로토타입을 알려줌으로써 어떤 foo인지 직접 알려준것임
}









