// 3_�Լ���ü4 -  137 page ���� ���κг���

int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 기계어 코드 치환, 빠르다.!!


	int(*f)(int, int) = &Add2; // 함수포인터에 담자

//	if (사용자 입력 == 1) f = &Add1;

	f(1, 2); // 치환? 호출? => 호출됨
}

//   핵심1. 인라인 치환 문법은 컴파일 시간에 동작하는 문법입니다.
//		2. 인라인 함수라도 함수 포인터에 담아서 호출하면 인라인 치환되지 않습니다.
