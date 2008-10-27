#ifndef _APP_H_
#define _APP_H_

#include <wx/app.h>
#include <wx/colour.h>
#include <wx/image.h>
#include <wx/string.h>
#include <wx/window.h>

class App: public wxApp
{
public:
	void AddToChat(wxString& data, wxColour& clr);
	void BuildWindowMenu();
	wxImage* ChatlineLogo();
	void EnableThem() {}
	unsigned short GetIDfromIndex(unsigned short d);
	unsigned short GetIndexFromID(unsigned short d);
	void LoadPrefs();
	void ParseWinLocData(wxWindow* w, wxString& data, wxString& Default);
	void SetDefaults();
	void SetupWizard();
	wxString* SmallSystemFont() const;
	unsigned short SmallSystemSize() const;
	
	bool GetChatWinOpen() const							{return mChatWinOpen;}
	void SetChatWinOpen(bool b)							{mChatWinOpen = b;}
	wxString* GetChatWinPos() const						{return mChatWinPos;}
	void SetChatWinPos(wxString& s)						{mChatWinPos = s;}
	bool GetDidByMenu() const							{return mDidByMenu;}
	void SetDidByMenu(bool b)							{mDidByMenu = b;}
	wxImage* GetServerBannerPic() const					{return mServerBannerPic;}
	void SetServerBannerPic(wxImage& o)					{mServerBannerPic = o;}
	bool GetSlimQueueCanvas() const						{return mSlimQueueCanvas;}
	void SetSlimQueueCanvas(bool b)						{mSlimQueueCanvas = b;}
	wxString* GetTrackerAddress() const					{return mTrackerAddress;}
	void SetTrackerAddress(wxString& s)					{mTrackerAddress = s;}
	unsigned short GetWindowMenuCount() const			{return mWindowMenuCount;}
	void SetWindowMenuCount(unsigned short n)			{mWindowMenuCount = n;}
private:
	bool mChatWinOpen;
	wxString* mChatWinPos;
	bool mDidByMenu;
	wxImage* mServerBannerPic;
	bool mSlimQueueCanvas;
	wxString* mTrackerAddress;
	unsigned short mWindowMenuCount;
};

#endif