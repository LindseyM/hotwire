#ifndef _WINDOW_TRACKER_H_
#define _WINDOW_TRACKER_H_

#include <wx/string.h>
#include <wx/window.h>

class WindowTracker
{
public:
	unsigned short Height;
	bool IsOpen;
	int Left;
	int Top;
	unsigned short Width;

	WindowTracker();
	~WindowTracker();

	void LoadFromString(wxString* s);
	void LoadFromWindow(wxWindow* w);
	void OwnWindow(wxWindow* w);
	wxString* SaveToString();
};

#endif