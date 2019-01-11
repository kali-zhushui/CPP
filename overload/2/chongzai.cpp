#include<iostream>
using namespace std;
class person{
	int age;
	int num;
public:
	person(){}
	person(int age,int num){
		this->age=age;
		this->num=num;
	}
	void print(){
	cout<<"age+"<<age<<"\t"<<"num="<<num<<endl;
	}
	person operator++(int){//有int表示后增，只是一个标识
		person per;
		per.age=age++;
		per.num=num++;
		return per;

	}
	person operator++(){
		person per;
		per.age=++age;
		per.num=++num;
		return per;
	}
};
int main()
{
person per1(18,66);
person per2=per1++;
per2.print();
person per3=++per1;
per3.print();
return 0;
}

