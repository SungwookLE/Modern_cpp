#include <iostream>
#include <string>
#include <vector>
#include <array>

// ÇÙ½É : Setter ¸¸µé±â #2

class People
{
private:
	std::string name;
	int age;
	std::array<int, 32> data;
public:
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}
	void set_data(const std::array<int, 32>& d)
	{
		data = d;
	}
};

int main()
{
	std::string s = "hello";
	std::array<int, 32> arr = {0};

	People p;

	p.print_msg(s);
	p.set_data(arr);
}








