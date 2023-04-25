// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();
	if (ret == 0)
	{
	}
	// C+17 부터 위 코드를 아래 처럼 표현 가능합니다.
	// "if with init" 이라는 문법 입니다.
	if (int ret2 = foo(); ret ==0){
		// ret2는 여기서만 사용가능


	}	// <== 파괴.

	// 아래 처럼하면 안되나요?
	if (foo() ==0){
		// foo 반환값(ret2) 를 사용못합니다.
	}

	// ----------------------
	// switch 도 가능
	switch (int n = foo(); n)
	{
	case 1:
		/* code */
		break;
	case 2:
		break;
	default:
		break;
	}
	// ------------
	// while 도 될까요?
	// => 안됩니다. if 와 switch만 가능 ...
	// => 만들지 않은 이유는 "for"문이 있기 때문
	
	// while (int cnt = 0; cnt < 9){
	// 	++cnt;
	// }

	

}