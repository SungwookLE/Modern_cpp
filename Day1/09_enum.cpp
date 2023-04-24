// 9_enum - 32 page


// 인자로 요일을 요구
void foo(int dayofaweek) {}

enum DAYOFWEEK{
	sun =0,
	mon=1
};

int main()
{
	foo(0);  
	foo(sun); // 위 코드보다 가독성이 좋다.

	// 위 코드의 단점 1. 이름 충돌 가능성
	int sun = 10;
	foo(sun); // enum 상수? 지역변수? => 지역변수
	foo(DAYOFWEEK::sun); // 이렇게 써라 

	// 2. 기존 enum 상수는 int로 변환 가능
	int week = DAYOFWEEK::sun; // ok

	foo(DAYOFWEEK::sun); // 이렇게 써라 
	foo(100); // 근데 enum 자체가 int 다 보니까.. 이런 유저 오류가 빈번하게 발생할 수 있다.
}





