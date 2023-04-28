# MODERN CPP
> SungwookLE  
> Date: '23.4.24~4.28  

## Ref
1. isocpp.org
2. cppreference.com
3. godbolt.org
4. https://github.com/codenuri/moderncpp
---

![](img/2023-04-24-16-54-23.png)
- after C+98: C+11, C+14, C+17 ,... 


### note
1. best practice in setter(class member)
```c++
class People
{
private:
 std::string name;
 int age;

public:
 // C++98 시절의 코드
 // C++98 시절 : 100점
 // C++11 이후 : best 는 아닙니다. move 지원안되는 setter
 void set(const std::string& n) { name = n; } // 항상 복사
 // void set(const std::string& n) {name = std::move(n);}
 // n은 상수 객체이므로 항상 복사
 
 // setter 만들 때 move 지원하려면 2개 만들어야 합니다.
 // c++11 이후에 최선의 코드입니다.
 // 해결책 1. 2개 만드세요.
 void set(const std::string& n) { name = n;}
 void set(std::string&& n){name = std::move(n);}

 // 해결책 2. T&& 사용하면 위 2개를 자동생성합니다.
 template<typename T>
 void set(T&& n){
 name = std::forward<T>n; 
 			// lvalue로 보내면 복사 
 			// rvalue로 보내면 move 
 }
};
```

2. lambda expression
```c++
// 람다표현식의 정확한 모양
 auto f1 = [](int a, int b) -> int
 { return a + b; };
 auto f0 = [v1, v2](int a){return a+v1+v2;}; // ok

 // 1. return 문장이 한개라면 리턴 타입 생략가능
 auto f2 = [](int a, int b)
 { return a + b; };

 // 2. return 문장이 여러개라도 동일 타입이면 생략 가능
 auto f3 = [](int a, int b)
 { if (a==1) return a; return b; };

 // 3. 다른 타입을 반환하는 return 문이 있으면 표기해야 한다.
 // => 아래 코드는 리턴 타입 표기하지 않으면 error
 auto f3 = [](int a, double b)
 { if (a==1) return a; return b; }; // error
 auto f3 = [](int a, double b) -> double
 { if (a==1) return a; return b; }; // 반환 타입 명시
```

3. SFINAE
- SFINAE(Substitution Failure Is not a error) 함수를 찾는 과정에서 대입해서  만들다 실패해도, 다른 대안의(후순위의) 함수 잇다고 하면 이건 에러는 아니다!

4. dangling: 매달린
- Dangling Pointer(Reference): 가리키던 곳이 지원진 상태의 포인터, 항상 주의해야한다.

5. mangling:
- python 에서 `__init__()` 과 같이 __를 붙여서 이름을 바꿔버리는 것인데, 이름을 바꿔어서 private 속성을 부여한다던지 하는 방법이다.