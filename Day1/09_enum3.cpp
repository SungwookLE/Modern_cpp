#include <iostream>
#include <type_traits>

// 아래처럼 만들면 각 요소는 int로 관리됩니다.
// enum class DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 };

// 각 요소를 char 타입으로 관리
enum class DAYOFWEEK : char {SUN=0, MON=1, TUE=2};

int main()
{
    using type = std::underlying_type<DAYOFWEEK>::type;

    std::cout << typeid(type).name() << std::endl; // char
}




