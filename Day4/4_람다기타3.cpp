int main()
{
	auto swap = [](int& a, int& b) { int tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;
}