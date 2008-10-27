#ifndef _WINDOW_TRACKER_H_
#define _WINDOW_TRACKER_H_

#include <wx/wx.h>

class WindowTracker
{
public:
	WindowTracker();
	~WindowTracker();

	void LoadFromString(wxString& s);
	void LoadFromWindow(wxWindow& w);
	void OwnWindow(wxWindow& w);
	wxString* SaveToString();
	
	unsigned short GetHeight() const						{return mHeight;}
	void SetHeight(unsigned short n)						{mHeight = n;}
	bool GetIsOpen() const									{return mIsOpen;}
	void SetIsOpen(bool b)									{mIsOpen = b;}
	int GetLeft() const										{return mLeft;}
	void SetLeft(int n)										{mLeft = n;}
	int GetTop() const										{return mTop;}
	void SetTop(int n)										{mTop = n;}
	unsigned short GetWidth() const							{return mWidth;}
	void SetWidth(unsigned short n)							{mWidth = n;}
private:
	unsigned short mHeight;
	bool mIsOpen;
	int mLeft;
	int mTop;
	unsigned short mWidth;
};

#endif