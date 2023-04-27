// 1_함수객체7.cpp

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less { inline bool operator()(int a, int b) { return a < b; } };
struct Greater { inline bool operator()(int a, int b) { return a > b; } };

template<typename T>
void foo(T f){
	bool b = f(1,2); // A
}

int main(){
	Less f1;
	Greater f2;
	foo(cmp1); // foo(bool(*)(int, int))	=> 치환 안됨
	foo(cmp2); // foo(bool(*)(int, int))	=> 안됨
	foo(f1);   // foo(Less)					=> 치환 가능
	foo(f2);   // foo(Greater)				=> 치환 가능

}
// 1. foo 함수는 몇개 생성될까요?: 3개
// 2. 각 foo 함수에서 "A" 부분의 인라인 치환에 대해서 생각해 보세요.
// 3. foo와 main을 제외하고 기계어 코드로 생성된 함수는 무엇이 있을까요?

// godbolt.org에 .. 함수객체 3번 복사해 넣으세요.

// MS 컴파일러로 인라인 치환 결과 보려면 "/Ob1" 옵션사용하면됩니다.
// g++ 컴파일러 최적화 옵션 "-O2"
