/**
 * 《UEFI编程实践》随书代码
 * 更多的UEFI探索，可以参考笔者的博客和专栏：
 * CSDN: https://blog.csdn.net/luobing4365
 * 知乎: https://www.zhihu.com/column/c_1233025362843209728
 * **/
// EchoClientUDP6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <Ws2tcpip.h>	//InetPton() 头文件

#pragma comment(lib,"ws2_32")//引入库函数

#define BUFFER_SIZE 1024
void ErrorOutput(char * msg);
int main(int argc, char* argv[])
{
	WSADATA wsaData;
	SOCKET hSocket = INVALID_SOCKET;
	char message[BUFFER_SIZE];
	int strLen;
	//SOCKADDR_IN6 servAdr;
	addrinfo hins = { 0 };
	addrinfo *servAddr = NULL;
	char pBuffer[256];

	if (argc != 3) {
		printf("UDP6 Client.Usage: %s <IP> <port>", argv[0]);
		exit(1);
	}
	else
	{
		printf("Ready to start UDP6 Client. IP=%s,port=%d\n", argv[1], atoi(argv[2]));
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorOutput("Start WSA error,Quit!");

	hins.ai_family = AF_INET6;
	hins.ai_socktype = SOCK_DGRAM;
	//1 获取server端地址
	if (0 != getaddrinfo(argv[1], argv[2], &hins, &servAddr))
		ErrorOutput("getaddrinfo() error");
	if (0 == getnameinfo(servAddr->ai_addr, servAddr->ai_addrlen, pBuffer, sizeof(pBuffer), NULL, 0, NI_NUMERICHOST))
	{
		//2 建立socket
		hSocket = socket(servAddr->ai_family, SOCK_DGRAM, servAddr->ai_protocol);
		//3 连接服务端
		if (connect(hSocket, servAddr->ai_addr, servAddr->ai_addrlen) == SOCKET_ERROR)
			ErrorOutput("connect() error");
		else
			puts("Connect.......");
		//4 与服务端通信
		while (1)
		{
			fputs("Input message(Q to quit):", stdout);
			fgets(message, BUFFER_SIZE, stdin);

			if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
				break;

			send(hSocket, message, strlen(message), 0);
			strLen = recv(hSocket, message, BUFFER_SIZE - 1, 0);
			message[strLen] = 0;
			printf("Message from server:%s", message);
		}

		closesocket(hSocket);
		WSACleanup();
	}
	else
		ErrorOutput("getnameinfo() error");
    return 0;
}

//处理错误
void ErrorOutput(char * msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}