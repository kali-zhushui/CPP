#include <iostream>
#include<stdlib.h>
#include"winsock2.h"
#pragma comment(lib,"ws2_32lib")
using namespace std;

DWORD WINAPI threadpro(LPVOID pParam)
{
	SOCKET hsock=(SOCKET)pParam;
	char buffer[1024];
	char sendBuffer[1024];
	if(hsock!=INVALID_SOCKET)
		cout<<"Start Receive"<<endl;
	
	//循环接受发送的内容
	while(hsock!=INVALID_SOCKET) 
	{
		int num = recv(hsock,buffer,1024,0);
		if(num>=0)
			cout<<"Receiving from client: "<<buffer<<endl;
		
		if(!strcmp(buffer,"A"))
		{
			memset(sendBuffer,0,1024);
			strcpy(sendBuffer,"B");
			int ires=send(hsock,sendBuffer,sizeof(sendBuffer),0);//回送
				if(ires==-1)
				{
					cout<<"ires="<<ires<<endl<<"One of the client was disconnected"<<endl;
					return 0;
				}
			cout<<"Send to client: "<<sendBuffer<<endl;
		}
		
		else if(!strcmp(buffer,"C"))
		{
			memset(sendBuffer,0,1024);
			strcpy(sendBuffer,"D");
			int ires=send(hsock,sendBuffer,sizeof(sendBuffer),0);//回送
				if(ires==-1)
				{
					cout<<"ires="<<ires<<endl<<"One of the client was disconnected"<<endl;
					return 0;
				}
			cout<<"Send to client: : "<<sendBuffer<<endl;
		}
		
		else if(!strcmp(buffer,"exit"))
		{
			cout<<"Client Close"<<endl;
			cout<<"Server Process Close"<<endl;
			return 0;
		}
		else
		{
				memset(sendBuffer,0,1024);
				strcpy(sendBuffer,buffer);
				int ires=send(hsock,sendBuffer,sizeof(sendBuffer),0);
				if(ires==-1)
				{
					cout<<"ires="<<ires<<endl<<"One of the client was disconnected"<<endl;
					return 0;
				}
				cout<<"Send to client: "<<sendBuffer<<endl;
		}
	}
	return 0;
}


int main()
{
	int conn=0;
    WSADATA wsd;
	WSAStartup(MAKEWORD(2,2),&wsd);
	SOCKET m_SockServer;
	sockaddr_in serveraddr;
	sockaddr_in serveraddrfrom;
	SOCKET m_Server[20];
	
	serveraddr.sin_family = AF_INET;//设置服务器地址家族
	serveraddr.sin_port = htons(4600);//设置服务器端口号
	serveraddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	
	m_SockServer = socket(AF_INET,SOCK_STREAM,0);
	
	int i = bind(m_SockServer,(sockaddr*)&serveraddr,sizeof(serveraddr)); 
	cout<<"bind:"<<i<<endl;
	
	int iMaxConnect=20;
	int iConnect=0;
	int iLisRet;
	char buf[]="THIS IS SERVER\0";
	char WarnBuf[]="It is Voer Max connect\0";
	int len=sizeof(sockaddr);
	
	while(1){

		iLisRet=listen(m_SockServer,0);
		m_Server[iConnect]=accept(m_SockServer,(sockaddr*)&serveraddrfrom,&len);
		
		cout<<"The client's ip is "<<inet_ntoa(serveraddrfrom.sin_addr)<<endl;
		
		if(m_Server[iConnect]!=INVALID_SOCKET)
		{
			int ires=send(m_Server[iConnect],buf,sizeof(buf),0);
			++conn;
			cout<<"accept:"<<conn<<endl;
			iConnect++;
			
			if(iConnect>iMaxConnect)
			{
				int ires=send(m_Server[iConnect],WarnBuf,sizeof(WarnBuf),0);
			}
			else{
				HANDLE m_Handle;
				DWORD nThreadld = 0;
				m_Handle = (HANDLE)::CreateThread(NULL,0,threadpro,(LPVOID)m_Server[--iConnect],0,&nThreadld);
			}
		}
		
		
	}
    WSACleanup();
	return 0;
}
