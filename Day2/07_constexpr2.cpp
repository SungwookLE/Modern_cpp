// c+11 에서 추가된 constexpr 상수

// constexpr : 컴파일 시간에 값을 알아야 한다.
// const : readonly 변수를 만드는 것

int main()
{
	int n = 0;
	std::cin >> n ; //  n은 실행시간에 이력 받을 수 있습니다.

	const int c1 = 0; // ok
	const int c2 = n; // ok. n은 변수이므로 컴파일 할 때 초기값을 알 수 없다.

	constexpr int c3 = 0;  // ok
	constexpr int c4 = n;  // error. 컴파일 할 때 초기값을 알아야 한다.!


	int arr[c1]; // C++은 허용되지만, 다른 언어는 readonly는 허용안합니다.
				 // (ex: RUST, C#)

}