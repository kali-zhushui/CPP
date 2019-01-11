#include<iostream>
using namespace std;
template<class Type>
class CList{
	class CList *header;
	int sum;
	public:
	static int ListValue;
	CList(){
		header=NULL;
		sum=0;
	}
};
class CNode{
	public:
		CNode *next;
		int data;
		CNode(){
			next=NULL;
			data=0;
		}
};
class CNet{
	public:
		CNet *next;
		int data;
		CNet(){
			next=NULL;
			data=0;
		}
};
template<class Type>
int CList<Type>::ListValue=3000;
int main(){
	CList<CNode>nodelist;
	nodelist.ListValue=7667;
	CList<CNet>netlist;
	cout<<netlist.ListValue<<endl;
	cout<<nodelist.ListValue<<endl;
	return 0;
}