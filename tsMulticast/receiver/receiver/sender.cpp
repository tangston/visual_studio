#include "stdafx.h"
//接收端
int main(int argc, _TCHAR* argv[])
{
	WSADATA WSAData;
	WORD sockVersion = MAKEWORD(2, 2);//初始化套接字
	if (WSAStartup(sockVersion, &WSAData) != 0)
		return 0;
	SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);//设置套接字类型为udp，ipv4
	if (INVALID_SOCKET == clientSocket)
	{
		cout << "socket error!";
		return 0;
	}

	//----------------------------设置目标地址与端口
	sockaddr_in dstAddr;
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_port = htons(8888);
	dstAddr.sin_addr.S_un.S_addr = inet_addr("234.2.2.2");//客户端要加入的组播地址
	//-------如果还要接受组播里的信息，本机就要bind端口和组播地址

	//--------绑定完后拿buffer监听，用recvfrom接受

	const char* sendData = "来自客户端的数据包 ";
	sendto(clientSocket, sendData, strlen(sendData), 0, (sockaddr*)&dstAddr, sizeof(dstAddr));
	//clientSocket 套接字  ，sendData 发送的数据，size 发送数据的长度
	//Flags 调用方式标志位, 一般为0, 改变Flags，将会改变Sendto发送的形式
	//addr  指针，指向目的套接字的地址，len addr所指地址的长度

	//下面的关闭可以放在退出程序的析构函数里面
	closesocket(clientSocket);
	WSACleanup();

	return 0;
}
