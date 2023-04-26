// 6_forwarding_reference1 - 아주 아주 중요!
void f1(int&  r) {}
// f1(n); : ok
// f1(0); : error
void f2(int&& r) {}
// f2(n): error
// f2(0): ok

// 함수 인자로
// int& : int 타입의 lvalue만 받겠다는 것   => (called lvalue reference)
// int&&: int 타입의 rvalue만 받겠다는 것   => (called rvalue reference)

// T& : 모든 타입의 lvalue만 받을 수 있다.  => (called lvalue reference)

// T&& : 모든 타입의 lvalue 와 rvalue 를 모두 받을 수 있다. => (called forward reference)
//  => universal reference 라고 부르자고 "effective c++" 저자가 제안"
//  => 하지만, C++ 표준위원회는 이후에, "forwarding reference" 라는 이름을 사용하기로 결정

// 핵심1:       "받을 수 있다" 라는 말은 "받을 수 있는 함수를 생성한다"는 것
// 핵심2:       생성된 함수는 모두 call by value 가 아닌 reference !!!

/* 아래 과정 외워야 함 ㅎㅎ*/
// lvalue 전달 f4(n): T=?       T&&=       최종함수 f4(?)
// rvalue 전달 f4(3): T=?       T&&=       최종함수 f4(?)


template<typename T> void f3(T& a)
{
}
// int main(){
//     int n = 0;
//     // 1. 사용자가 타입을 명시적으로 전달하는 경우
//     f3<int>(n);     // T=int      T&= int&   f3(int& a)
//     f3<int&>(n);    // T=int&      T&= int& &   f3(int& a)
//     f3<int&&>(n);   // T=int&&      T&= int&& &   f3(int& a)

//     // 2. 사용자가 타입을 전달하지 않는 경우
//     // => 함수 인자를 보고 T 타입 결정 후 함수 생성
//     f3(3);   // 3을 보고 T를 int로 deduction 하였는데, T = int, int& int&& 중 어떠한 것으로 결정하려 해도 3을 받을 수 있는 방법은 없다.. error
//     f3(n);  // T=int로 결정됨

// }


template<typename T> void f4(T&& a)
{
}
int main(){
    int n = 0;

    // 1. 타입을 명시적으로 전달하는 경우
    f4<int>(3);     // T=int    T&& = int &&     f4(int&& a)
    f4<int&>(n);    // T=int&   T&& = int& &&   f4(int& a)
    f4<int&&>(3);   // T=int&&  T&& = int&& &&  f4(int&& a)

    // 2. 타입인자를 전달하지 않으면 함수인자를 보고 타입을 결정
    // => 컴파일러가 T를 어떻게 결정했을지 예측해 보세요.
                
                
                // 1. n은 int이므로 T=int로 결정하면 f4(int&&) 함수 생성
                //  => f4(n)은 에러 !!
                // 2. T=int& 로 결정하면 f4(int&) 함수 생성되므로
                //  => f4(n)은 에러 아님
    f4(n);      // T=int&    T&& = int& &&      f4(int& a)

    f4(3);      // T=int    T&& = int&&        f4(int&& a)
}
