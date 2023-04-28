// Step3. 모든 값 보관하기 - 핵심!!!

template<typename ... Types> struct tuple{
	static constexpr int N = 0; 
};

// tuple 사용시 최소 한개 이상의 타입이 있는 경우를 위한 부분 특수화
template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types ...>
{
    using base = tuple<Types...>;
    T value;

    tuple() = default;
    tuple(const T& n, const Types& ... args)
        : value(n), base( args ... ) {}

    // static constexpr int N = 기반클래스::N + 1;
    static constexpr int N = base::N + 1;

};



int main()
{
	tuple<                   > t0;                      // primary 버전 사용
	tuple<              short> t1;                      // short 보관
	tuple<      double, short> t2;                      // double 보관
	tuple<int,  double, short> t3(10, 3.4, 2);          // int 보관

}
// 컴파일 시간에 재귀를 사용해서 기반 클래스를 계속 만들면서 상속받는 코드!