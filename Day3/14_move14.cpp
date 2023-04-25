#include <iostream>
#include <string>
#include <vector>
#include <array>

// ÇÙ½É : Setter ¸¸µé±â #3

class People
{
private:
	std::string name;
	std::string address;
public:
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name,			   addr);
	p.set(std::move(name), addr);
	p.set(name,			   std::move(addr));
	p.set(std::move(name), std::move(addr));
}








