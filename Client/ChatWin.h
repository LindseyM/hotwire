#ifndef _CHAT_WIN_H_
#define _CHAT_WIN_H_

#include <wx/wx.h>

class ChatWin: public wxFrame
{
public:
	void ResetEntryFieldFormatting();
	
	void OnClose(wxCommandEvent& event);
	void OnMoved(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
	void OnResized(wxCommandEvent& event);
private:
	wxTextCtrl* mChatFld;
	wxTextCtrl* mTextFld;
	wxToolBar* mToolBar;
};

#endif