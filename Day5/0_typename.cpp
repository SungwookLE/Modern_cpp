// 2_typename

struct Test
{
	enum { data = 0 };
	using DWORD = int;
};

int p1 = 0;

template<typename T> void foo(T a)
{
	// �Ʒ� �ڵ忡�� * �� �ǹ̸� ������ ������
	Test::data  * p1; 
	Test::DWORD * p1; 	
}


int main()
{
	Test t;
	foo(t);
}



