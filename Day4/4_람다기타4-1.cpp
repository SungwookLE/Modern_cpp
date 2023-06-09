class CompilerGeneratedName
{
	int v1;

public:
	CompilerGeneratedName(int n) : v1(n) {}
	inline int operator()(int a, int b) const { return a + b; }

	using PF = int (*)(int, int);

	// 캡처한 람다 표현식은 아래 static 함수를 만들 수 없습니다.
	// 그래서 함수 포인터로 변환될 수 없습니다.
	static int helper(int a, int b) { return a + b + v1; }

	operator PF() { return &CompilerGeneratedName::helper; }
};
int main()
{
	int v1 = 0;
	int (*f)(int, int) = CompilerGeneratedName(v1);

	// 캡처한 람다 표현식은 함수 포인터로 변환될 수 없습니다.
	// => 아래 코드는 에러입니다.
	// => 캡처하지 않은 람다표현식만 함수 포인터로 변환됩니다.
	// int(*f)(int, int) = [v1](int a, int b){return a+b+v1;};
}
