#pragma once

#include "Setting.h"

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include "afxwin.h"

// CDlgFont 对话框
#define NARROWFONT 1
#define WIDEFONT 2
class CFontLattice
{
public:
    CFontLattice();
    ~CFontLattice();
	CFontLattice(CFontLattice&& rhs);
	CFontLattice& operator=(CFontLattice&& rhs);

    unsigned int	utf_16_code;
    unsigned char	width;
    unsigned char*	p_data;
};

class CDlgFont : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFont)

public:
	CDlgFont(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgFont();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FONT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
protected:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedButtonFont();
    afx_msg void OnBnClickedButtonSave();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

private:
    CString m_edit_source;
    CString m_edit_unicode;
    CString m_edit_font_name;
    CString m_edit_save_name;

private:
	std::shared_ptr<CSetting> m_pSetting;

    LOGFONT m_logFont;
    int m_nCurrentFontHeight;
	int m_nMaxCurrentFontWidth;
	int m_nShowLeft;
	int m_nShowTop;
    std::map<unsigned int, CFontLattice> m_mCurrentNarrowMap;
	std::map<unsigned int, CFontLattice> m_mCurrentWideMap;
private:
    void ShowFontSample();
	void ShowFontFlush();

	void UpdateFontSize();

    int GetCharInfo(CClientDC& dc, wchar_t character, const LOGFONT& logFont, bool bTestSample = false);
    int GetStringInfo(const wchar_t* str, const LOGFONT& logFont);

    int WriteLatticeDataToCppFile(std::ofstream& file);

	static CFontLattice GetEmptyFont(SIZE size);
	/// @param  nFontSize  [IN]  0 16*19 ; 1 8*19
	std::string StringFromFontLattice(const CFontLattice& elem, int nFontSize, int flagOfNarrowWide);
};

// 字符串转化
/**
* @brief  UNICODE字符串转多字节字符串
* @param  ws [IN]  UNICODE字符串
* @return 多字节字符串
*/
std::string ws2s(const std::wstring& ws);
/**
* @brief  多字节字符串转UNICODE字符串
* @param  s [IN]  多字节字符串
* @return UNICODE字符串
*/
std::wstring s2ws(const std::string& s);
/**
* @brief  UNICODE字符串转utf8字符串
* @param  ws [IN]  UNICODE字符串
* @return utf8字符串
*/
std::string ws2utf8(const std::wstring& ws);
/**
* @brief  多字节字符串转utf8字符串
* @param  s [IN]  多字节字符串
* @return utf8字符串
*/
std::wstring utf82ws(const std::string& s);