// tcp.cpp : 定义控制台应用程序的入口点。
#include"winsock2.h"
#include<stdlib.h>
#pragma comment(lib,"ws2_32.lib")
#include<string.h>
#include<iostream>
using namespace std;

int main(int argc,char* argv[]){
// 1、调用WSAStartup初始化Winsock
	// WSADATA wsd;
	// WSAStartup(MAKEWORD(2,2),&wsd);
// 2、调用socket创建一个会话socket
	 SOCKET sockfd;
	 struct sockaddr_in server_addr;
	 struct sockaddr_in clientaddr;
	 memset(&serveraddr,0,sizeof(struct,sockaddr_in server_addr.sin_family=AF_INET));
	 serveraddr.sin_family=AF_INET;
	 serveraddr.sin_port=htonl(PORTWOM);
	 serveraddr.sin_addr.s_un.s_addr=htonl();
// 3、绑定socket
	int i=bind(sockfd,(struct sockaddr*)&serveraddr);
// 4、调用listen设置登台连接状态
	listen(sockfd,0);
		int addr_len=sizeof(struct sockaddr);
	while(1){
// 5、调用accept接受连接并生成会话socket
		accept(sockfd,(struct sockaddr*)&clientaddr,addr_len);
		
	}
// 6、调用send和recv发送或者接受数据
// 7、调用closesocket关闭Socket
return 0;	
}
