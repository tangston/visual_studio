// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include<WinSock2.h>
#include<Ws2tcpip.h>	//ip_mreq头文件
#include<iostream>
#pragma comment(lib,"ws2_32.lib")//			链接socket库
using namespace std;
// TODO: 在此处引用程序需要的其他头文件
