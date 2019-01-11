#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "winsock2.h"
#pragma comment(lib,"ws2_32.lib")
#define PORTNUM 4600
#define SIZE 128 
using namespace std;

int main(int argc, char *argv[])
{
    
    //1、初始化Winsock
    WSADATA wsd;
    WSAStartup(MAKEWORD(2,2),&wsd);
    //2、创建socket
    char buf[SIZE];
    SOCKET m_Sockfd;
    struct sockaddr_in serveraddr;
    //struct sockaddr_in serveraddrfrom;
    //SOCKET m_Server[20];
    
    memset(&serveraddr,0,sizeof(struct sockaddr_in));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORTNUM);
    serveraddr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    m_Sockfd=socket(AF_INET,SOCK_STREAM,0);
    
    while(1){
       connect(m_Sockfd,(const struct sockaddr *)&serveraddr,sizeof(struct sockaddr));
       cout<<"please input data: ";
       cin>>buf;
       send(m_Sockfd,buf,SIZE,0);
       closesocket(m_Sockfd);
    }
    cout << "continue ...";
    cin.get();
    return 0;
}
