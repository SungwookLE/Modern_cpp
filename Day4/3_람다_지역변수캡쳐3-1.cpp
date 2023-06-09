// 3_람다지역변수캡처3-1.cpp
#include <functional>
#include <iostream>

// reference capture는 항상 dangling의 위험성이 있습니다.
int main(){
	std::function<void(int)> f;

	{
		int n = 10;
		f = [&n](int a){n=a;};

		f(10); // ok .. n = 10;
	}

	f(10);  // 버그 ..
			// n=10 을 실행해야 하는데.. n은 파괴되었습니다.
			// 항상 레퍼런스 캡처는 주의해야 합니다. 
}

// Dangling Pointer(Reference): 가리키던 곳이 지원진 상태의 포인터, 항상 주의해야한다.
// C/C++ : 개발자가 주의해야 한다. (너무 어렵다.)
// Rust	 : Dangling Reference 가 발생할 확률이 있으면 컴파일 에러!

// int* p = new int;
// delete p;
// *p = 10;	
			// 지워진 메모리이므로 사용하면 안됩니다. (표준 문서)
		    // => 사용하면 어떻게 되나요?? 알수 없습니다.
			// 컴파일러, 실행환경에 따라 다양합니다.