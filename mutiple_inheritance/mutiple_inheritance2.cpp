#include<iostream>
using namespace std;
class perA{
public:
	int numA;
	void display(){
	cout<<"this is perA"<<endl;
	}	
	perA(){
	cout<<"perA"<<endl;
	}
	~perA(){
	cout<<"~perA"<<endl;
	}
};
class perB{
	public:
	void display(){
	cout<<"this is perB"<<endl;
	}
	perB(){
		cout<<"perB"<<endl;
	}
	~perB(){
		cout<<"~perB"<<endl;
	}
};
class stu:public perB,public perA{
public:
int stuC;
/*void display(){
	cout<<"this is stu"<<endl;
	}*/
	stu(){
	cout<<"stu"<<endl;
	}
	~stu(){
	cout<<"~stu"<<endl;
	}
};
void run(){
	stu stu1;
	stu1.perA::display();
}
int main(){
	run();
	cout<<"continue...";
	return 0;
}

