#pragma once
#include "ControlBase.h"

#define					BUTTOM				1
#define					EDIT				2

class CEditEx : public CControlBaseFont
{
	DUIOBJ_DECLARE_CLASS_NAME(CEditEx, "edit")
public:
	CEditEx(HWND hWnd, CDuiObject* pDuiObject);
	CEditEx(HWND hWnd, CDuiObject* pDuiObject, UINT uControlID, CRect rc, CString strTitle= TEXT(""), BOOL bPassWord = FALSE, BOOL bIsVisible = TRUE, BOOL bIsDisable = FALSE, BOOL bIsPressDown = FALSE);
	virtual ~CEditEx(void);

	// �������СͼƬ
	bool SetLeftBitmap(UINT nResourceID, CString strType = TEXT("PNG"));
	bool SetLeftBitmap(CString strImage);
	HRESULT OnAttributeLeftImage(const CStringA& strValue, BOOL bLoading);

	// �����Ҳ�СͼƬ
	bool SetSmallBitmap(UINT nResourceID, CString strType = TEXT("PNG"));
	bool SetSmallBitmap(CString strImage);
	HRESULT OnAttributeSmallImage(const CStringA& strValue, BOOL bLoading);

	virtual void SetControlRect(CRect rc);
	virtual BOOL SetControlFocus(BOOL bFocus);
	virtual BOOL IsDraw(CPoint point) ;
	virtual void SetControlWndVisible(BOOL bIsVisible);
	virtual void SetControlTitle(CString strTitle);
	BOOL GetLButtonDown();
	BOOL GetLButtonUp();
	CString GetEditText();

	virtual LRESULT OnMessage(UINT uID, UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
	virtual BOOL OnControlMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnControlLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnControlLButtonUp(UINT nFlags, CPoint point);
	virtual void DrawControl(CDC &dc, CRect rcUpdate);

	virtual	void SetControlDisable(BOOL bIsDisable);

	void ShowEdit();
	void HideEdit();
	
public:
	Image*			m_pLeftImage;		// ���СͼƬ
	CSize			m_sizeLeftImage;	// ���СͼƬ��С
	int				m_nLeftImageCount;	// ���СͼƬ�ĸ���

	Image*			m_pSmallImage;		// �Ҳ�СͼƬ
	CSize			m_sizeSmallImage;	// �Ҳ�СͼƬ��С
	BOOL			m_bIsSmallButton;	// �Ҳ�СͼƬ�Ƿ���Ϊ��ť������
	int				m_nSmallImageCount;	// �Ҳ�СͼƬ�ĸ���

	bool			m_bPassWord;		// ��������
	bool			m_bMultiLine;		// ����
	bool			m_bAutoHScroll;		// ˮƽ����
	bool			m_bAutoVScroll;		// ��ֱ����
	bool			m_bNumber;			// ֻ����������
	bool			m_bReadOnly;		// ֻ��
	int				m_nMaxChar;			// ����ַ���

	bool			m_bDown;
	bool			m_bDownTemp;
	enumButtonState m_buttonState;
	enumButtonState m_EditState;
	CRect			m_rcText;			// ���ֲ���λ��

	Color			m_clrText;			// ������ɫ
	Color			m_clrTooltip;		// ��ʾ��Ϣ��ɫ
	CFont			m_fontTemp;			// ����������
	CEdit*			m_pEdit;			// Windowsԭ������ؼ�

	DUI_DECLARE_ATTRIBUTES_BEGIN()
		DUI_INT_ATTRIBUTE("password", m_bPassWord, FALSE)
		DUI_INT_ATTRIBUTE("multiline", m_bMultiLine, FALSE)
		DUI_INT_ATTRIBUTE("autohscroll", m_bAutoHScroll, FALSE)
		DUI_INT_ATTRIBUTE("autovscroll", m_bAutoVScroll, FALSE)
		DUI_INT_ATTRIBUTE("number", m_bNumber, FALSE)
		DUI_INT_ATTRIBUTE("readonly", m_bReadOnly, FALSE)
		DUI_INT_ATTRIBUTE("maxchar", m_nMaxChar, FALSE)
		DUI_CUSTOM_ATTRIBUTE("left-image", OnAttributeLeftImage)
		DUI_CUSTOM_ATTRIBUTE("small-image", OnAttributeSmallImage)
		DUI_COLOR_ATTRIBUTE("crtext", m_clrText, FALSE)
		DUI_COLOR_ATTRIBUTE("crtip", m_clrTooltip, FALSE)
	DUI_DECLARE_ATTRIBUTES_END()
};