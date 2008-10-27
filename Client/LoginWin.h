#ifndef _LOGIN_WIN_H_
#define _LOGIN_WIN_H_

#include <wx/wx.h>

class LoginWin: public wxDialog
{
public:
	void OnActivate(wxCommandEvent& event);
	void OnDeactivate(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
private:
	wxTextCtrl* mAddressFld;
	wxStaticText* mAddressTxt;
	wxButton* mConnectBtn;
	wxTextCtrl* mLoginFld;
	wxStaticText* mLoginTxt;
	wxTextCtrl* mPasswordFld;
	wxStaticText* mPasswordTxt;
};

#endif