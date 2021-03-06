// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
using namespace std;
#pragma comment(lib, "Ws2_32.lib")
//IP报头
typedef struct icmp_hdr
{
	unsigned char icmp_type;      //消息类型
	unsigned char icmp_code;        //标志代码
	unsigned short icmp_checksum;        //校验和
	//----------------------------------下面是 回显头
	unsigned short icmp_id;        //通常设置为进程ID
	unsigned short icmp_sequence;    //序列号	
	unsigned long icmp_timestamp;        //时间戳
} ICMP_HDR, *PICMP_HDR;
//ICMP 报头 

typedef struct  ip_hdr {
	UCHAR iphVerLen;
	UCHAR ipTOS;
	USHORT ipLength;
	USHORT ipID;
	USHORT ipFlag;
	UCHAR ipTTL;
	UCHAR ipProtocol;
	USHORT ipCheckSum;
	ULONG ipSource;
	ULONG ipDestination;
} IPHeader, *PIPHeader;

USHORT checksum(USHORT *pBuf, int iSize);
BOOL SetTimeOut(SOCKET s, int nTime, BOOL bRecv);