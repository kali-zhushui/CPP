#include<iostream>
using namespace std;

template <class Type>
void Swap(Type &a,Type &b)
{
	Type temp;
	temp=a;
	a=b;
	b=temp;
}
int main(){
	int a=12,b=16;
	
	swap(a,b);
	cout<<a<<endl<<b;
}