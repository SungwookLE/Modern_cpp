#include <vector>
#include <iostream>

// 컨테이너 버전: 컨테이너의 begin을 다시 호출
template<typename T>
auto mybegin(T& c){
    return c.begin();
}

// 배열 버전: 핵심은 템플릿 모양입니다.
template<typename T, unsigned int SZ>
T* mybegin(T(&arr)[SZ]){return arr;}

template<typename T, unsigned int SZ>
T* myend(T(&arr)[SZ]){return arr+SZ-1;}


int main(){
    std::vector<int> v = {1,2,3};
    int x[3] = {1,2,3};

    auto p1 = mybegin(v);
    auto p2 = mybegin(x);
    auto p3 = myend(x);

    std::cout << *p2 << std::endl;
    std::cout << *p3 << std::endl;
}