#include<iostream>
#include<string>
using namespace std;
class solution {
public:
	int strtoint(string str)
	{
		int num = 0;
		for (size_t i = 0; i < str.size(); ++i)
		{
			num = num * 10;
			num = num + str[i] - '0';
		}
		return num;
	}
};
int main()
{
	cout << solution().strtoint("1234") << endl;
}