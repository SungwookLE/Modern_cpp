// 7_가변인자템플릿1 - 225 page
// 가변인자 클래스 템플릿

template<typename T> class vector
{
};

template<typename T> class tuple
{
};


int main()
{
	vector<int> v1;			// ok
	vector<int, double> v2;	// error

	tuple<int> t1;
}