// C++ 98 시절의 enum
// enum DAYOFWEEK { sun = 0, mon = 1};

// C++11 의 새로운 enum: 
// 			enum class를 쓰는게 대세입니다.!!
enum class DAYOFWEEK {sun =0 , mon =1};

void foo(DAYOFWEEK w){
	int n = static_cast<int>(w); // ok!.. 만약 enum class의 값을 int로 바꾸어서 연산을 하고 싶으면 이것처럼 해라
}

int main(){
	// int n1 = sun; 	// error. DAYOFWEEK 이름 반드시 필요
	//int n2 = DAYOFWEEK::sun;	// error. int로 변환 안됨

	DAYOFWEEK n3 = DAYOFWEEK::sun; // ok..
									// 핵심: 보다 엄격하게 사용하라는 것

	foo(DAYOFWEEK::sun);
	// foo(100); // error
}