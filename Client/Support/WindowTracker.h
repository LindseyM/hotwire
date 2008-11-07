#ifndef _WINDOW_TRACKER_H_
#define _WINDOW_TRACKER_H_

#include <wx/wx.h>

class WindowTracker
{
public:
	unsigned short mHeight;
	bool mIsOpen;
	int mLeft;
	int mTop;
	unsigned short mWidth;
	
	WindowTracker();
	~WindowTracker();

	void LoadFromString(wxString& s);
	void LoadFromWindow(wxWindow& w);
	void OwnWindow(wxWindow& w);
	wxString* SaveToString();
};

#endif