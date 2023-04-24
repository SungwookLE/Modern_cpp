class Meter{
	int value;
	public:
	Meter(int n ): value(n){}
};

// 정수형 리터럴 접미사는 반드시 인자로 "unsigned long long"으로 해야 합니다.
// 사용자가 만들때는 반드시 "_" 로 시작해야 한다.
// "_" 로 시작하지 않은 것은 C++ 표준에서 예약

// Meter operator""m(unsigned long long n){
Meter operator""_m(unsigned long long n){
	Meter me( static_cast<int>(n));
	return me;
}


int main()
{
	// 모든 리터럴은 타입이 있습니다.
	double d = 3.4; // 3.4는 double
	float f = 3.4f; // 리터럴 접미사 "f"는 리터럴을 float로 해석해 달라는 것

	// C+11 부터 사용자가 리터럴 접미사를 만들 수 있게 되었습니다.
	Meter n1 = 3_m; // 이 순간 컴파일러는 약속된 함수를 찾게됩니다.

	// Gram n2 = 3gram;

}




