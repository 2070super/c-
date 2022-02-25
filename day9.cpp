#include<iostream>
#include<string>
using namespace std;
class solution
{
public:
	int strtoint(string str)
	{
		int n = str.size();
		if (n < 1)
			return 0;
		else
			return n;
	}
};
int main()
{
	cout << solution().strtoint("hello") << endl;
	cout << solution().strtoint(string("hello")) << endl;
}