// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS


// TODO: 在此处引用程序需要的其他头文件
#include <iostream>
#include <winsock2.h>       
#include <ws2tcpip.h>
#include <Ws2tcpip.h>
using namespace std;

#pragma comment(lib, "Ws2_32.lib")

//IP报头
typedef struct IP_HEADER
{
	unsigned char hdr_len : 4;       //4位头部长度
	unsigned char version : 4;       //4位版本号
	unsigned char tos;             //8位服务类型
	unsigned short total_len;      //16位总长度
	unsigned short identifier;     //16位标识符
	unsigned short frag_and_flags; //3位标志加13位片偏移
	unsigned char ttl;             //8位生存时间
	unsigned char protocol;        //8位上层协议号
	unsigned short checksum;       //16位校验和
	unsigned long sourceIP;        //32位源IP地址
	unsigned long destIP;          //32位目的IP地址
} IP_HEADER;

//ICMP报头
typedef struct ICMP_HEADER
{
	BYTE type;    //8位类型字段
	BYTE code;    //8位代码字段
	USHORT cksum; //16位校验和
	USHORT id;    //16位标识符
	USHORT seq;   //16位序列号
} ICMP_HEADER;

//报文解码结构
typedef struct DECODE_RESULT
{
	USHORT usSeqNo;        //序列号
	DWORD dwRoundTripTime; //往返时间
	in_addr dwIPaddr;      //返回报文的IP地址
}DECODE_RESULT;