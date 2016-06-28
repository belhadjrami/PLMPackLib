// CLayoutIntroCtrl.h  : Declaration of ActiveX Control wrapper class(es) created by Microsoft Visual C++

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CLayoutIntroCtrl

class CLayoutIntroCtrl : public CWnd
{
protected:
	DECLARE_DYNCREATE(CLayoutIntroCtrl)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x97304D8, 0x999D, 0x45D3, { 0x91, 0x53, 0x1D, 0x1F, 0x97, 0x1E, 0x15, 0xC1 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// Attributes
public:

// Operations
public:

	CString get_ToString()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL Equals(VARIANT obj)
	{
		BOOL result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x60020001, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, &obj);
		return result;
	}
	long GetHashCode()
	{
		long result;
		InvokeHelper(0x60020002, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN GetType()
	{
		LPUNKNOWN result;
		InvokeHelper(0x60020003, DISPATCH_METHOD, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	VARIANT GetLifetimeService()
	{
		VARIANT result;
		InvokeHelper(0x60020004, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT InitializeLifetimeService()
	{
		VARIANT result;
		InvokeHelper(0x60020005, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH CreateObjRef(LPUNKNOWN requestedType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60020006, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, requestedType);
		return result;
	}
	LPDISPATCH get_Site()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020007, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void putref_Site(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020007, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	void add_Disposed(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020009, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Disposed(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002000a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void Dispose()
	{
		InvokeHelper(0x6002000b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH get_Container()
	{
		LPDISPATCH result;
		InvokeHelper(0x6002000c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL get_AllowDrop()
	{
		BOOL result;
		InvokeHelper(0x6002000d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_AllowDrop(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x6002000d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_AutoSize()
	{
		BOOL result;
		InvokeHelper(0x60020011, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_AutoSize(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020011, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPUNKNOWN get_LayoutEngine()
	{
		LPUNKNOWN result;
		InvokeHelper(0x60020015, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	unsigned long get_BackColor()
	{
		unsigned long result;
		InvokeHelper(DISPID_BACKCOLOR, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_BackColor(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(DISPID_BACKCOLOR, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_BackgroundImage()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020018, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void putref_BackgroundImage(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020018, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	LPUNKNOWN get_ContextMenu()
	{
		LPUNKNOWN result;
		InvokeHelper(0x6002001c, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	void putref_ContextMenu(LPUNKNOWN newValue)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x6002001c, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_ContextMenuStrip()
	{
		LPDISPATCH result;
		InvokeHelper(0x6002001e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void putref_ContextMenuStrip(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002001e, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	LPUNKNOWN get_Cursor()
	{
		LPUNKNOWN result;
		InvokeHelper(0x60020020, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	void putref_Cursor(LPUNKNOWN newValue)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60020020, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_Focused()
	{
		BOOL result;
		InvokeHelper(0x60020024, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN get_Font()
	{
		LPUNKNOWN result;
		InvokeHelper(DISPID_FONT, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	void putref_Font(LPUNKNOWN newValue)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(DISPID_FONT, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	unsigned long get_ForeColor()
	{
		unsigned long result;
		InvokeHelper(DISPID_FORECOLOR, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_ForeColor(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(DISPID_FORECOLOR, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Text()
	{
		CString result;
		InvokeHelper(0x6002002f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Text(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x6002002f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void ResetBackColor()
	{
		InvokeHelper(0x60020032, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ResetCursor()
	{
		InvokeHelper(0x60020033, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ResetFont()
	{
		InvokeHelper(0x60020034, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ResetForeColor()
	{
		InvokeHelper(0x60020035, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ResetRightToLeft()
	{
		InvokeHelper(0x60020036, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Refresh()
	{
		InvokeHelper(0x60020037, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ResetText()
	{
		InvokeHelper(0x60020038, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL get_InvokeRequired()
	{
		BOOL result;
		InvokeHelper(0x60020039, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH BeginInvoke(LPDISPATCH method, SAFEARRAY * args)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002003a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, method, args);
		return result;
	}
	VARIANT EndInvoke(LPDISPATCH asyncResult)
	{
		VARIANT result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002003b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, asyncResult);
		return result;
	}
	VARIANT Invoke_2(LPDISPATCH method, SAFEARRAY * args)
	{
		VARIANT result;
		static BYTE parms[] = VTS_DISPATCH  ;
		InvokeHelper(0x6002003c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, method, args);
		return result;
	}
	long get_Handle()
	{
		long result;
		InvokeHelper(DISPID_HWND, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN get_DataBindings()
	{
		LPUNKNOWN result;
		InvokeHelper(0x60020041, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN get_BindingContext()
	{
		LPUNKNOWN result;
		InvokeHelper(0x60020042, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	void putref_BindingContext(LPUNKNOWN newValue)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60020042, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_AccessibilityObject()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020044, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_AccessibleDefaultActionDescription()
	{
		CString result;
		InvokeHelper(0x60020045, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_AccessibleDefaultActionDescription(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020045, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_AccessibleDescription()
	{
		CString result;
		InvokeHelper(0x60020047, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_AccessibleDescription(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020047, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_AccessibleName()
	{
		CString result;
		InvokeHelper(0x60020049, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_AccessibleName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020049, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void add_AutoSizeChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002004d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_AutoSizeChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002004e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_BackColorChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002004f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_BackColorChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020050, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_BackgroundImageChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020051, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_BackgroundImageChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020052, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_BackgroundImageLayoutChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020053, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_BackgroundImageLayoutChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020054, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void ResetBindings()
	{
		InvokeHelper(0x60020055, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void add_BindingContextChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020056, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_BindingContextChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020057, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	long get_Bottom()
	{
		long result;
		InvokeHelper(0x60020058, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL get_CanFocus()
	{
		BOOL result;
		InvokeHelper(0x6002005a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL get_CanSelect()
	{
		BOOL result;
		InvokeHelper(0x6002005b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL get_Capture()
	{
		BOOL result;
		InvokeHelper(0x6002005c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Capture(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x6002005c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_CausesValidation()
	{
		BOOL result;
		InvokeHelper(0x6002005e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_CausesValidation(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x6002005e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void add_CausesValidationChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020060, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_CausesValidationChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020061, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_ClientSizeChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020065, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_ClientSizeChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020066, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	CString get_CompanyName()
	{
		CString result;
		InvokeHelper(0x60020067, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL get_ContainsFocus()
	{
		BOOL result;
		InvokeHelper(0x60020068, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void add_ContextMenuChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020069, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_ContextMenuChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002006a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_ContextMenuStripChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002006b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_ContextMenuStripChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002006c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	LPUNKNOWN get_Controls()
	{
		LPUNKNOWN result;
		InvokeHelper(0x6002006d, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	BOOL get_Created()
	{
		BOOL result;
		InvokeHelper(0x6002006e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void add_CursorChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002006f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_CursorChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020070, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	BOOL get_IsDisposed()
	{
		BOOL result;
		InvokeHelper(0x60020071, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL get_Disposing()
	{
		BOOL result;
		InvokeHelper(0x60020072, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void add_DockChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020073, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_DockChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020074, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	BOOL get_Enabled()
	{
		BOOL result;
		InvokeHelper(DISPID_ENABLED, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Enabled(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(DISPID_ENABLED, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void add_EnabledChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020077, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_EnabledChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020078, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_FontChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020079, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_FontChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002007a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_ForeColorChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002007b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_ForeColorChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002007c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	BOOL get_HasChildren()
	{
		BOOL result;
		InvokeHelper(0x6002007d, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long get_Height()
	{
		long result;
		InvokeHelper(0x6002007e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Height(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6002007e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_IsHandleCreated()
	{
		BOOL result;
		InvokeHelper(0x60020080, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL get_IsAccessible()
	{
		BOOL result;
		InvokeHelper(0x60020081, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IsAccessible(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020081, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_IsMirrored()
	{
		BOOL result;
		InvokeHelper(0x60020083, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long get_Left()
	{
		long result;
		InvokeHelper(0x60020084, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Left(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x60020084, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void add_LocationChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020088, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_LocationChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020089, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_MarginChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002008c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_MarginChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002008d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x6002008e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Name(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x6002008e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_Parent()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020090, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void putref_Parent(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020090, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_ProductName()
	{
		CString result;
		InvokeHelper(0x60020092, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_ProductVersion()
	{
		CString result;
		InvokeHelper(0x60020093, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL get_RecreatingHandle()
	{
		BOOL result;
		InvokeHelper(0x60020094, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN get_Region()
	{
		LPUNKNOWN result;
		InvokeHelper(0x60020095, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	void putref_Region(LPUNKNOWN newValue)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60020095, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	void add_RegionChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020097, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_RegionChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020098, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	long get_Right()
	{
		long result;
		InvokeHelper(0x60020099, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void add_RightToLeftChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002009a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_RightToLeftChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002009b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_SizeChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002009e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_SizeChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002009f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	long get_TabIndex()
	{
		long result;
		InvokeHelper(0x600200a0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_TabIndex(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x600200a0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void add_TabIndexChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200a2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_TabIndexChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200a3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	BOOL get_TabStop()
	{
		BOOL result;
		InvokeHelper(DISPID_TABSTOP, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_TabStop(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(DISPID_TABSTOP, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void add_TabStopChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200a6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_TabStopChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200a7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	VARIANT get_Tag()
	{
		VARIANT result;
		InvokeHelper(0x600200a8, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void putref_Tag(VARIANT newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x600200a8, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, &newValue);
	}
	void add_TextChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200aa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_TextChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200ab, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	long get_Top()
	{
		long result;
		InvokeHelper(0x600200ac, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Top(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x600200ac, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_TopLevelControl()
	{
		LPDISPATCH result;
		InvokeHelper(0x600200ae, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL get_UseWaitCursor()
	{
		BOOL result;
		InvokeHelper(0x600200af, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UseWaitCursor(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x600200af, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_Visible()
	{
		BOOL result;
		InvokeHelper(0x600200b1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Visible(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x600200b1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void add_VisibleChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200b3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_VisibleChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200b4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	long get_Width()
	{
		long result;
		InvokeHelper(0x600200b5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Width(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x600200b5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPUNKNOWN get_WindowTarget()
	{
		LPUNKNOWN result;
		InvokeHelper(0x600200b7, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	void putref_WindowTarget(LPUNKNOWN newValue)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200b7, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	void add_Click(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200b9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Click(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200ba, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_ControlAdded(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200bb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_ControlAdded(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200bc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_ControlRemoved(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200bd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_ControlRemoved(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200be, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_DragDrop(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200bf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_DragDrop(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200c0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_DragEnter(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200c1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_DragEnter(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200c2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_DragOver(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200c3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_DragOver(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200c4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_DragLeave(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200c5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_DragLeave(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200c6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_GiveFeedback(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200c7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_GiveFeedback(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200c8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_HandleCreated(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200c9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_HandleCreated(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200ca, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_HandleDestroyed(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200cb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_HandleDestroyed(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200cc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_HelpRequested(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200cd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_HelpRequested(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200ce, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_Invalidated(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200cf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Invalidated(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200d0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_PaddingChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200d4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_PaddingChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200d5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_Paint(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200d6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Paint(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200d7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_QueryContinueDrag(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200d8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_QueryContinueDrag(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200d9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_QueryAccessibilityHelp(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200da, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_QueryAccessibilityHelp(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200db, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_DoubleClick(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200dc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_DoubleClick(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200dd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_Enter(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200de, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Enter(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200df, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_GotFocus(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200e0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_GotFocus(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200e1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_KeyDown(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200e2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_KeyDown(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200e3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_KeyPress(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200e4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_KeyPress(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200e5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_KeyUp(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200e6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_KeyUp(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200e7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_Layout(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200e8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Layout(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200e9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_Leave(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200ea, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Leave(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200eb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_LostFocus(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200ec, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_LostFocus(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200ed, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_MouseClick(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200ee, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_MouseClick(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200ef, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_MouseDoubleClick(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200f0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_MouseDoubleClick(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200f1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_MouseCaptureChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200f2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_MouseCaptureChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200f3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_MouseDown(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200f4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_MouseDown(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200f5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_MouseEnter(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200f6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_MouseEnter(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200f7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_MouseLeave(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200f8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_MouseLeave(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200f9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_MouseHover(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200fa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_MouseHover(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x600200fb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_MouseMove(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200fc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_MouseMove(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200fd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_MouseUp(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200fe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_MouseUp(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x600200ff, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_MouseWheel(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60020100, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_MouseWheel(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60020101, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_Move(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020102, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Move(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020103, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_PreviewKeyDown(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60020104, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_PreviewKeyDown(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60020105, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_Resize(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020106, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Resize(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020107, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_ChangeUICues(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60020108, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_ChangeUICues(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60020109, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_StyleChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002010a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_StyleChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002010b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_SystemColorsChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002010c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_SystemColorsChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002010d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_Validating(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x6002010e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Validating(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x6002010f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_Validated(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020110, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Validated(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020111, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_ParentChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020112, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_ParentChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020113, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	LPDISPATCH BeginInvoke_2(LPDISPATCH method)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020114, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, method);
		return result;
	}
	void BringToFront()
	{
		InvokeHelper(0x60020115, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL Contains(LPDISPATCH ctl)
	{
		BOOL result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020116, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ctl);
		return result;
	}
	LPUNKNOWN CreateGraphics()
	{
		LPUNKNOWN result;
		InvokeHelper(0x60020117, DISPATCH_METHOD, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	void CreateControl()
	{
		InvokeHelper(0x60020118, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH FindForm()
	{
		LPDISPATCH result;
		InvokeHelper(0x6002011b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL Focus()
	{
		BOOL result;
		InvokeHelper(0x6002011c, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN GetContainerControl()
	{
		LPUNKNOWN result;
		InvokeHelper(0x6002011f, DISPATCH_METHOD, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH GetNextControl(LPDISPATCH ctl, BOOL forward)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_DISPATCH VTS_BOOL ;
		InvokeHelper(0x60020120, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ctl, forward);
		return result;
	}
	void Hide()
	{
		InvokeHelper(0x60020121, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Invalidate(LPUNKNOWN Region)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60020122, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Region);
	}
	void Invalidate_2(LPUNKNOWN Region, BOOL invalidateChildren)
	{
		static BYTE parms[] = VTS_UNKNOWN VTS_BOOL ;
		InvokeHelper(0x60020123, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Region, invalidateChildren);
	}
	void Invalidate_3()
	{
		InvokeHelper(0x60020124, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Invalidate_4(BOOL invalidateChildren)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020125, DISPATCH_METHOD, VT_EMPTY, NULL, parms, invalidateChildren);
	}
	VARIANT Invoke_3(LPDISPATCH method)
	{
		VARIANT result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020128, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, method);
		return result;
	}
	void PerformLayout()
	{
		InvokeHelper(0x60020129, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void PerformLayout_2(LPDISPATCH affectedControl, LPCTSTR affectedProperty)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_BSTR ;
		InvokeHelper(0x6002012a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, affectedControl, affectedProperty);
	}
	void ResumeLayout()
	{
		InvokeHelper(0x60020130, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ResumeLayout_2(BOOL PerformLayout)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020131, DISPATCH_METHOD, VT_EMPTY, NULL, parms, PerformLayout);
	}
	void Scale(float ratio)
	{
		static BYTE parms[] = VTS_R4 ;
		InvokeHelper(0x60020132, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ratio);
	}
	void Scale_2(float dx, float dy)
	{
		static BYTE parms[] = VTS_R4 VTS_R4 ;
		InvokeHelper(0x60020133, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dx, dy);
	}
	void Select()
	{
		InvokeHelper(0x60020135, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL SelectNextControl(LPDISPATCH ctl, BOOL forward, BOOL tabStopOnly, BOOL nested, BOOL wrap)
	{
		BOOL result;
		static BYTE parms[] = VTS_DISPATCH VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL ;
		InvokeHelper(0x60020136, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ctl, forward, tabStopOnly, nested, wrap);
		return result;
	}
	void SendToBack()
	{
		InvokeHelper(0x60020137, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void SetBounds(long x, long y, long Width, long Height)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x60020138, DISPATCH_METHOD, VT_EMPTY, NULL, parms, x, y, Width, Height);
	}
	void Show()
	{
		InvokeHelper(0x6002013a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void SuspendLayout()
	{
		InvokeHelper(0x6002013b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Update()
	{
		InvokeHelper(0x6002013c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_ImeMode()
	{
		long result;
		InvokeHelper(0x6002013d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ImeMode(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6002013d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void add_ImeModeChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002013f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_ImeModeChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020140, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void ResetImeMode()
	{
		InvokeHelper(0x60020141, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL get_AutoScroll()
	{
		BOOL result;
		InvokeHelper(0x60020142, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_AutoScroll(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020142, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPUNKNOWN get_HorizontalScroll()
	{
		LPUNKNOWN result;
		InvokeHelper(0x6002014a, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN get_VerticalScroll()
	{
		LPUNKNOWN result;
		InvokeHelper(0x6002014b, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN get_DockPadding()
	{
		LPUNKNOWN result;
		InvokeHelper(0x6002014c, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	void ScrollControlIntoView(LPDISPATCH activeControl)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002014d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, activeControl);
	}
	void add_Scroll(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x6002014e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Scroll(LPUNKNOWN value)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x6002014f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void SetAutoScrollMargin(long x, long y)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x60020150, DISPATCH_METHOD, VT_EMPTY, NULL, parms, x, y);
	}
	BOOL ValidateChildren()
	{
		BOOL result;
		InvokeHelper(0x60020153, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_activeControl()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020155, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void putref_activeControl(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020155, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	void add_AutoValidateChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002015b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_AutoValidateChanged(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002015c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	LPDISPATCH get_ParentForm()
	{
		LPDISPATCH result;
		InvokeHelper(0x6002015e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void PerformAutoScale()
	{
		InvokeHelper(0x6002015f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL Validate()
	{
		BOOL result;
		InvokeHelper(0x60020160, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL Validate_2(BOOL checkAutoValidate)
	{
		BOOL result;
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020161, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, checkAutoValidate);
		return result;
	}
	void add_AutoSizeChanged_2(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020162, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_AutoSizeChanged_2(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020163, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_AutoValidateChanged_2(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020166, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_AutoValidateChanged_2(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x60020167, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	long get_BorderStyle()
	{
		long result;
		InvokeHelper(0x60020168, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_BorderStyle(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x60020168, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void add_Load(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002016a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_Load(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002016b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void add_TextChanged_2(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002016c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void remove_TextChanged_2(LPDISPATCH value)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x6002016d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
	}
	void setDrawingName(LPCTSTR drawingName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x6002016e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, drawingName);
	}
	CString GetOutputFile()
	{
		CString result;
		InvokeHelper(0x6002016f, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void setFormatsFileName(LPCTSTR fileNameFormats)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60020170, DISPATCH_METHOD, VT_EMPTY, NULL, parms, fileNameFormats);
	}


};
