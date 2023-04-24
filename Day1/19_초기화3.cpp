int main()
{
	int  n1 = 3.4; 	// ok... 에러는 아니고, 경고 발생
					// 그런데, 아주 나쁜 코드 C/C++ 제외한 거의 모든 언어는 에러

	char c1 = 500;  // ok... 그런데, 오버플로우 발생
					// 나쁜 코드.

	// 중괄호 초기화는 아래와 같은 케이스를 방지해줘서 좋음
	// brace initialization => uniform initialization 이 대세임

	// prevent narrow - 56 page 중간부분
	int n2{ 3.4 };  
	char c2{ 500 }; 

}