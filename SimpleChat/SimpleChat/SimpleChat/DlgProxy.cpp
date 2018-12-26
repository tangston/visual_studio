
// DlgProxy.cpp: 实现文件
//

#include "stdafx.h"
#include "SimpleChat.h"
#include "DlgProxy.h"
#include "SimpleChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimpleChatDlgAutoProxy

IMPLEMENT_DYNCREATE(CSimpleChatDlgAutoProxy, CCmdTarget)

CSimpleChatDlgAutoProxy::CSimpleChatDlgAutoProxy()
{
	EnableAutomation();

	// 为使应用程序在自动化对象处于活动状态时一直保持
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。  设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CSimpleChatDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CSimpleChatDlg)))
		{
			m_pDialog = reinterpret_cast<CSimpleChatDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CSimpleChatDlgAutoProxy::~CSimpleChatDlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CSimpleChatDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CSimpleChatDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSimpleChatDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_ISimpleChat 的支持来支持类型安全绑定
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {05462393-207b-4510-a9e1-ebecd5bcb3ec}
static const IID IID_ISimpleChat =
{0x05462393,0x207b,0x4510,{0xa9,0xe1,0xeb,0xec,0xd5,0xbc,0xb3,0xec}};

BEGIN_INTERFACE_MAP(CSimpleChatDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CSimpleChatDlgAutoProxy, IID_ISimpleChat, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏在此项目的 StdAfx.h 中定义
// {ac8f8dfa-7879-49cc-959a-65dbdd09e435}
IMPLEMENT_OLECREATE2(CSimpleChatDlgAutoProxy, "SimpleChat.Application", 0xac8f8dfa,0x7879,0x49cc,0x95,0x9a,0x65,0xdb,0xdd,0x09,0xe4,0x35)


// CSimpleChatDlgAutoProxy 消息处理程序
