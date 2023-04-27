int main()
{
	auto swap = [](auto &a, auto &b)
	{ 
		auto tmp = std::move(a); 
		a = std::move(b); 
		b = std::move(tmp); 
	};

	int n = 10;
	double d = 3.4;

	swap(n, d); // 서로 다른 데이터 타입인데 스왑을 한다?? 안되지 <- 문제점...
	
	// C+14 generic 람다: 인자가 서로 다른 템플릿!!!
	// C+20 template 람다가 도입되었습니다.

	auto swap2 = []<typename T>(T& a, T& b){T tmp = std::move(a), a = std::move(b), b= std::move(tmp);};
	swap2(n,d);
	
}