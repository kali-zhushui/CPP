#include <iostream>
#include<stdlib.h>
#include"winsock2.h"
#include<time.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

int main(int argc, char *argv[])
{
	WSADATA wsd;
	WSAStartup(MAKEWORD(2,2),&wsd);
	SOCKET m_SockClient;
	sockaddr_in clientaddr;
	
	
	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port=htons(4600);
	clientaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	m_SockClient = socket(AF_INET,SOCK_STREAM,0);
	int i=connect(m_SockClient,(sockaddr*)&clientaddr,sizeof(clientaddr));
	cout<<"connect: "<<i<<endl;
	char buffer[1024];
	char inBuf[1024];
	int num;
	num=recv(m_SockClient,buffer,1024,0);
	if(num>0)
	{
		cout<<"Receive from server:127.0.0.1 "<<buffer<<endl;
		while(1)
		{
			num=0;
			cin>>inBuf;
			if(!strcmp(inBuf,"exit"))
			{
				send(m_SockClient,inBuf,sizeof(inBuf),0);
				return 0;
			}
			send(m_SockClient,inBuf,sizeof(inBuf),0);
			num=recv(m_SockClient,buffer,1024,0);
			if(num>=0)
				cout<<"Receive from server: "<<buffer<<endl;
		}
	}
}
