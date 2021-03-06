// tsMulticast.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"



int main(int argc, _TCHAR* argv[])
{
	WSADATA WSAData;
	WORD sockVersion = MAKEWORD(2, 2);
	if (WSAStartup(sockVersion, &WSAData) != 0)
		return 0;

	SOCKET serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);	//创建服务器套接字
	if (INVALID_SOCKET == serSocket)
	{
		cout << "socket error!";
		return 0;
	}
	//---------------------------------------------以上套接字初始化完毕


	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;//设置传输协议
	serAddr.sin_port = htons(8888);//端口
	serAddr.sin_addr.S_un.S_addr = INADDR_ANY;//目的地址

	if (bind(serSocket, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)	 //将socket绑定地址 
	{
		cout << "bind error";
		closesocket(serSocket);
		return 0;
	}


	/* ip_mreq的定义
	typedef struct ip_mreq {
	IN_ADDR imr_multiaddr;  // IP multicast address of group.
	IN_ADDR imr_interface;  // Local IP address of interface.
	} IP_MREQ, *PIP_MREQ;
	*/
	ip_mreq multiCast;//监听组播组
	multiCast.imr_interface.S_un.S_addr = INADDR_ANY;		//本地任意网络设备接口的IP地址。
	multiCast.imr_multiaddr.S_un.S_addr = inet_addr("234.2.2.2");	//224.0.1.0～238.255.255.255为用户可用的组播地址（临时组地址
	setsockopt(serSocket, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*)&multiCast, sizeof(multiCast));
	sockaddr_in clientAddr;
	int iAddrlen = sizeof(clientAddr);
	char buff[1024];	//建立接收缓存字节数组 
	while (true)
	{
		memset(buff, 0, 1024);	//清空接收缓存数组
								//开始接收数据 
		int len = recvfrom(serSocket, buff, 1024, 0, (sockaddr*)&clientAddr, &iAddrlen);
		if (len>0)
		{
			cout << "客户端地址：" << inet_ntoa(clientAddr.sin_addr) << endl;
			cout << buff<<endl;

			// sendto(serSocket,buff,1024,0,(sockaddr*)&clientAddr,iAddrlen);
		}
	}

	closesocket(serSocket);		//关闭socket 
	WSACleanup();

	
    return 0;
}

