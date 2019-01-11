#include<iostream>
using namespace std;
class A{
	public:
	void print()
	{cout<<"A"<<endl;}
	
};
class B:public A{

};
class C:public A{

};
class D:public B,public C{

};
int main()
{
D d;
d.print();
return 0;
}
