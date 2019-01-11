#include<stdexcept>//标准异常的使用方法
#include<iostream>
using namespace std	;

class stu{};

int main()
{
	try{
		throw logic_error("11");
	}
	catch(logic_error){
		cout<<"捕获stu异常"<<endl;
	}
	catch(int i){
		cout<<"捕获int异常"<<endl;
	}
	catch(...){
		cout<<"捕获其他异常"<<endl;
	}
}