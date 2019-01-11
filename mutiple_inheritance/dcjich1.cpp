#include<iostream>
using namespace std;
class person{
public:
	void eat(){
		cout<<"can eat"<<endl;
	}
};
class stu:public person{
public:
	void study(){
		cout<<"students learning how to survival..\n"<<endl;
	}
};
void func(){
	stu stu1;
	stu1.eat();
	stu1.study();
}
int main(){
	func();
	cout<<"continue..."<<endl;
	return 0;
}
