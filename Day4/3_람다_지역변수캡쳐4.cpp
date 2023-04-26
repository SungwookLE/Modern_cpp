// 149
int main()
{
	int v1 = 0, v2 = 0;

	auto f1 = [v1, &v2](int a) { ... };
	auto f2 = [&v1, v2](int a) { ... };

	auto f3 = [=](int a) { ... };
	auto f4 = [&](int a) { ... };

	auto f5 = [=, &v2](int a) { ... };
	auto f6 = [&, v2](int a) { ... };
	auto f7 = [&, &v2](int a) { ... };

	auto f8 = [x = v1, &y = v2](int a) { x, y };
}




