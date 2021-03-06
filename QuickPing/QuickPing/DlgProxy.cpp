
// DlgProxy.cpp: 实现文件
//

#include "stdafx.h"
#include "QuickPing.h"
#include "DlgProxy.h"
#include "QuickPingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQuickPingDlgAutoProxy

IMPLEMENT_DYNCREATE(CQuickPingDlgAutoProxy, CCmdTarget)

CQuickPingDlgAutoProxy::CQuickPingDlgAutoProxy()
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
		ASSERT_KINDOF(CQuickPingDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CQuickPingDlg)))
		{
			m_pDialog = reinterpret_cast<CQuickPingDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CQuickPingDlgAutoProxy::~CQuickPingDlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CQuickPingDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CQuickPingDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CQuickPingDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_IQuickPing 的支持来支持类型安全绑定
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {96cffe0f-e8de-41c9-8aa4-1800f17bf163}
static const IID IID_IQuickPing =
{0x96cffe0f,0xe8de,0x41c9,{0x8a,0xa4,0x18,0x00,0xf1,0x7b,0xf1,0x63}};

BEGIN_INTERFACE_MAP(CQuickPingDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CQuickPingDlgAutoProxy, IID_IQuickPing, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏在此项目的 StdAfx.h 中定义
// {e1d6eb09-924b-4426-bafe-077b612a9ddc}
IMPLEMENT_OLECREATE2(CQuickPingDlgAutoProxy, "QuickPing.Application", 0xe1d6eb09,0x924b,0x4426,0xba,0xfe,0x07,0x7b,0x61,0x2a,0x9d,0xdc)


// CQuickPingDlgAutoProxy 消息处理程序
