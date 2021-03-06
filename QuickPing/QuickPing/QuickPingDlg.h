
// QuickPingDlg.h: 头文件
//

#pragma once

class CQuickPingDlgAutoProxy;


// CQuickPingDlg 对话框
class CQuickPingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CQuickPingDlg);
	friend class CQuickPingDlgAutoProxy;

// 构造
public:
	CQuickPingDlg(CWnd* pParent = nullptr);	// 标准构造函数
	virtual ~CQuickPingDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUICKPING_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	CQuickPingDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedtext();
	afx_msg void OnStnClickedStatic();
	afx_msg void OnStnClickedStatic1();
	afx_msg void OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
private:
	CStatic ipAddress;
	CStatic to;
	CStatic Thread;
	CStatic OutOfTime;
	// ip查询的开始ip地址
	CIPAddressCtrl FirstIP;
	// ip地址的最后一个
	CIPAddressCtrl lastIP;
public:
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton1();
private:
	// 显示表格
	CListCtrl mylist;
	// 第一个ip
	DWORD First_ipAddress;
public:
	// 后一个ip
	DWORD Last_ipAddress;
};
