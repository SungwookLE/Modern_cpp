// 핵심: rvalue, lvalue의 개념은, 변수(객체)에 부여되는 개념이 아닌, 표현식(expression)에 부여되는 개념
// expression: 한개의 값으로 계산되는 코드 집합

//				lvalue vs. rvalue (표현식에 대한 개념이다.)
//				expression으로부터 생성된 한개의 값이 등호의 = 에 올 수 있는가?
// 				(메모리 할당 되었는가? 임시로 계산된 값인가?)

int main()
{
	int n = 0; // expression
	
	(n + 2) * 3 + 1; // expression

	(n + 1) = 10; // expression:  임시객체는 lvalue가 될 수 없음
	(n = 20) = 10; ; // expression:  n 은 lvalue가 될 수 있음

	++n = 10; // expression: n을 1먼저 증가시키고 n = 10 이라고 한거니까 lvalue 될 수 있음
	n++ = 10; // expression:  n을 1 증가시킨 임시의 값을 10으로 대입시키려고햇음. lvalue 될 수 없음 -> rvalue임
}