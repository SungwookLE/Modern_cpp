// 20_타입추론1 - 69p
// 타입추론문법

auto main()
{
	int x[3] = { 1,2,3 };

	// auto: 우변의 표현식으로 좌변의 타입을 결정
			// 컴파일 시간에 결정, 실행시간 오버헤드 없음 ..
	auto n = x[0];

	// decltype(exp) : () 안의 표현식의 타입 조사
	decltype(n) d; //int d

	// 아래 코드들의 타입을 예측해 보세요.
	const int c = 0;
	auto a1 = c; // 1. const int a1 = c
				// 2. int a1 = c ==> 정답 ..

	decltype(c) d1; // "const int d1"
					// 이 경우 const니까 초기값이 없으면 error

	// 타입 추론이란 (type deduction, type inference)
	// => 컴파일러가 타입을 결정하는 원리를 배우는 것

	// 타입 추론이 발생하는 3가지 경우
	// 1. template
	// 2. auto
	// 3. decltype
	// => 1, 2번은 동일한 규칙 사용
	// 		 3번은 다른 규칙



}