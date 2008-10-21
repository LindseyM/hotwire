#ifndef _APP_H_
#define _APP_H_

#include <wx/app.h>
#include <wx/colour.h>
#include <wx/image.h>
#include <wx/string.h>
#include <wx/window.h>

class App: public wxApp
{
	bool ChatWinOpen;
	wxString* ChatWinPos;
	bool DidByMenu;
	wxImage* ServerBannerPic;
	bool SlimQueueCanvas;
	wxString* TrackerAddress;
	unsigned short WindowMenuCount;

	void addToChat(wxString* data, wxColour* clr);
	void BuildWindowMenu();
	wxImage* ChatlineLogo();
	void EnableThem() {}
	unsigned short getIDfromIndex(unsigned short d);
	unsigned short getIndexFromID(unsigned short d);
	void LoadPrefs();
	void ParseWinLocData(wxWindow* w, wxString* data, wxString* Default);
	void SetDefaults();
	void SetupWizard();
	wxString* SmallSystemFont() const;
	unsigned short SmallSystemSize() const;
};

#endif