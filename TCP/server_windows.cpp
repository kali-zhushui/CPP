// tcp.cpp : �������̨Ӧ�ó������ڵ㡣
#include"winsock2.h"
#include<stdlib.h>
#pragma comment(lib,"ws2_32.lib")
#include<string.h>
#include<iostream>
using namespace std;

int main(int argc,char* argv[]){
// 1������WSAStartup��ʼ��Winsock
	// WSADATA wsd;
	// WSAStartup(MAKEWORD(2,2),&wsd);
// 2������socket����һ���Ựsocket
	 SOCKET sockfd;
	 struct sockaddr_in server_addr;
	 struct sockaddr_in clientaddr;
	 memset(&serveraddr,0,sizeof(struct,sockaddr_in server_addr.sin_family=AF_INET));
	 serveraddr.sin_family=AF_INET;
	 serveraddr.sin_port=htonl(PORTWOM);
	 serveraddr.sin_addr.s_un.s_addr=htonl();
// 3����socket
	int i=bind(sockfd,(struct sockaddr*)&serveraddr);
// 4������listen���õ�̨����״̬
	listen(sockfd,0);
		int addr_len=sizeof(struct sockaddr);
	while(1){
// 5������accept�������Ӳ����ɻỰsocket
		accept(sockfd,(struct sockaddr*)&clientaddr,addr_len);
		
	}
// 6������send��recv���ͻ��߽�������
// 7������closesocket�ر�Socket
return 0;	
}
