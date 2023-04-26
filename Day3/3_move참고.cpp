#include <string>

int main(){
    // move가 copy보다 성능이 좋습니다.
    // C++: 복사가 기본이고, move가 필요하면 std::move() 사용

    std::string s1  = "to be or not to be";
    std::string s2 = s1; // 복사(깊은 복사)
    std::string s3 = std::move(s1); // 이동

    // move를 기본으로 하고, 원할때만 복사하면 어떨까?
    // 아래 코드가 "Rust"입니다.
    let s1 = String::from("to be or not to be");
    let s2 = String::from("to be or not to be");

    let s3 = s1; // move!!
    let s4 = s2.clone(); // copy!!
}