#include"objectpool.h"
using namespace std;
int main()
{
	objectpool<int> o;
	int* a = o.New();
	int* b = o.New();
	cout << a << endl;
	cout << b << endl;
	o.Delete(a);
	int* c = o.New();
	cout << c << endl;
	return 0;
}