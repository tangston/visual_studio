// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include<WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
#define uchar unsigned char
#define ushort unsigned short
//PING 命令是用的简单网管协议
typedef struct icmp_head {
	uchar icmp_type;//消息类型
	uchar icmp_code;//代码
	uchar icmp_checksum;//校验和
	DWORD icmp_id;//消息类型
	DWORD icmp_sequence;//序列号
	DWORD icmp_timestamp;//时间戳


}ICMP_HEAD,*PICMP_HEAD;
// TODO: 在此处引用程序需要的其他头文件
