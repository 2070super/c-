#include<iostream>
using namespace std;
class A {
public:
	A(const char* s) { cout << s << endl; }
	~A() {}
};
class B :virtual public A
{
public:
	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};
class C :virtual public A
{
public:
	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl;}
};
class D :public B, public C
{
public:
	D( const char* s1, const char* s2, const char* s3, const char* s4) :B(s1, s2), C(s1, s3), A(s1)
	{
		cout << s4 << endl;
	}
};
int min() {
	D* p = new D("class A", "class B", "class C", "class D");
	delete p;
	return 0;
}
