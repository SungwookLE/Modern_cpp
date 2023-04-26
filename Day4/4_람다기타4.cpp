class ClosureType
{
public:
	inline int operator()(int a, int b) { return a + b; }
};
int main()
{
	auto f = [](int a, int b) {return a + b; }
}












