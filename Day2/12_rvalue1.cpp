// 4_rvalue - 87 page
int x = 0;
int  foo() {	return x;}
int& goo() { return x; }

// lvalue: 등호에 왼쪽에 올 수 있는 것 , 이름이 있고, 단일식을 넘어서 사용가능
//				& 연산자로 주소를 구할 수 있다. 참조를 반환하는 함수

// rvalue: 등호에 왼쪽에 올 수 없는 것, 이름이 없고, 단일식에서만 사용가능
//			& 연산자로 주소를 구할 수 없다. 값을 반환하는 함수
// 			리터럴 (10, 3.4 등), 임시 객체


int main()
{
	int v1 = 10, v2 = 10;

	v1 = 10; 	// v1: lvalue, 10: rvalue
	10 = v1;	//
	v2 = v1;


	// ------------------------------
	const int c =0;
	c = 20; // c는 lvalue? rvalue?
			// immutable, readonly한 lvalue라고 합니다.


	// 모든 rvalue는 상수이다?? => 아닙니다.
	Point(1,1).x = 10; // error !
					// 임시객체는 상수 아닙니다. 문법상 왼쪽에 못옴
	
	// Point(1,1).set(10,20)
}









