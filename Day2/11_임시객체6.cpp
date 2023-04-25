#include <string>

template<typename T>
const T& mymax(const T& a, const T& b){
    return a<b? b: a;
}

int main(){

    // 임시객체를 const& 로 수명연장할 수 있다.
    const std::string& s = std::string{"hello"};
    const std::string& ret = mymax(std::string{"A"}, std::string{"B"});
    
    // ret를 계속 사용해도 될까요?
    // => 사용하면 안됩니다.
    // => dangling reference 일 수 있습니다. 
    // => 임시객체를 최초에 가리킨 const& 로 만 수명 연장됩니다.

    // mymax()의 인자가 임시객체가 아니었따면 ret 사용가능
    // 임시객체 였다면 ret는 dangling reference

    //ret = "ASD"; error
}