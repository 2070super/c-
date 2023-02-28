#include <iostream>
using namespace std;
size_t gcd(size_t x, size_t y)
{
	if (y == 0)
	{
		return x;
	}
	return gcd(y, x % y);
}
int main()
{
	int  a, b;
	int count = 0;
	cin >> a >> b;
	size_t c = a * b;
	int z = sqrt(c);
	for (int i = 1; i <= z; i++)
	{
		if (c % i == 0&&gcd(i, c / i) == a)
		{
			count += 2;
		}
			
	}
	std::cout << count;
	return 0;
}
