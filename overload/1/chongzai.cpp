#include<iostream>
using namespace std;
class CBOOK{
protected:
    int page;
public:
    CBOOK(){};
    CBOOK(int page){
        this->page=page;//将page的值赋给protected中的page
    }
    CBOOK operator+(const int num){
        CBOOK book;
        book.page=page+num;
        return book;
    }
    void display(){
    cout<<"page="<<page<<endl;
    }
};
int main()
{
    CBOOK cbk1(10);
    CBOOK cbk2(20);
    cbk2=cbk1+20;
    cbk2.display();
    return 0;
}
