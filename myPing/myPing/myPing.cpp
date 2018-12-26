// myPing.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main(int argc,char **argv)
{
	WSADATA wsaData;
	SOCKET client;//原始套接字
	SOCKADDR_IN destAddr;//源地址
	struct hostent *host = NULL;
	int nTimeOut = 1000;
	char szSendBuffer[sizeof(ICMP_HEAD) + 32] = { 0 };//定义ICMP报文发送缓冲区
	char szRecvBuffer[1024];
	PICMP_HEAD picmp = (PICMP_HEAD)szSendBuffer;//PICMP指向发送缓冲区
	if (argc < 2) {//通过命令行方式获得的
		printf("输入目标主机的域名或ip地址\n");
		system("PAUSE");
		return 1;
	}
	//1.加载动态链接库
	WSAStartup(MAKEWORD(2, 2), &wsaData);//MAKEWORD 新变量的低字节序；BYTE bHigh //指定新变量的高字节序；
	//2.创建原始套接字
	client = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);//icmp的ping用的udp
	if (client == INVALID_SOCKET) {
		printf("socket()创建失败,错误码：%d\n", WSAGetLastError);
	}
	////3.设置接受超时时间
	setsockopt(client, SOL_SOCKET, SO_RCVTIMEO, (const char *)&nTimeOut, sizeof(nTimeOut));
	//4.设置目标主机地址
	host = gethostbyname(argv[1]);
	if (host == NULL) {
		printf("主机名解析失败\n");
		system("PAUSE");
		return 1;
	}
	destAddr.sin_addr.S_un.S_addr = *((unsigned long *)host->h_addr);
	destAddr.sin_family = AF_INET;
	destAddr.sin_port = htons(0);
	//5.  ICMP报文封装
	//ICMP_HEAD封装
	picmp->icmp_type = 8;
	picmp->icmp_code = 0;
	picmp->icmp_checksum = 0;
	picmp->icmp_id = GetCurrentProcessId();
	//数据封装
	memcpy((szSendBuffer + sizeof(ICMP_HEAD)), "ABCDEFGHIJKLMN", 32);
	//计算校验和
	picmp->icmp_checksum = checksum((PICMP_HEAD)szSendBuffer, sizeof(szSendBuffer));
	//6.向目标主机发送ICMP报文并接受回复ICMP报文
	struct sockaddr_in fromAddr;
	int sizeFrom = sizeof(SOCKADDR_IN);
	memset(szRecvBuffer, 0, 1023);
	//向目标主机发送一个ICMP报文
	int sendBytes = sendto(client, szSendBuffer, sizeof(szSendBuffer), 0, (SOCKADDR *)&destAddr, sizeof(destAddr));
	if (sendBytes == SOCKET_ERROR)
	{
		printf("发送错误");
	}
	return 0;
}
ushort checksum(PICMP_HEAD picmp, int leng) {
	long sum = 0;
	ushort *pusIcmp = (ushort *)picmp;
	while (leng>1)
	{
		sum += *(pusIcmp++);
		if (sum & 0x8000000) {
			sum = (sum & 0xffff) + (sum >> 16);
		}
		leng -= 2;
	}
	if (leng) {
		sum += *(uchar *)pusIcmp;	
	}
	while (sum>>16)
	{
		sum = (sum & 0xffff) + (sum >> 16);
	}
	return(ushort)~sum;//取反
}
