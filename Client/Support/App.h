#ifndef _APP_H_
#define _APP_H_

#include <wx/wx.h>
#include "ChatlineCore.h"
#include "../Files/TransferItem.h"
#include "WindowTracker.h"

#define BOOL_TO_CHAR(b) (b)?'y':'n'
#define BOOL_TO_INT(b) (b)?1:0
#define BOOL_TO_STRING(b) (b)?"true":"false"
#define BUILD "2008110601"
#define CHAR_TO_BOOL(text) (text)=='y'
#define INT_TO_BOOL(i) (i)==1

class App: public wxApp
{
public:
	wxString* mAwayMsg;
	wxString* mBlockedList;
	bool mBookmarksOpen;
	wxString* mCFont;
	bool mChatWinOpen;
	wxString* mChatWinPos;
	bool mClearChat;
	unsigned int mCSize;
	bool mCustIcon;
	bool mDidByMenu;
	unsigned short mDLGoing;
	bool mDLIC;
	wxString* mDLLoc;
	wxString* mDMLoc;
	bool mDMOpen;
	bool mDock;
	wxArrayString* Filenames;
	bool mForceMsg;
	wxImage* mIconPic;
	bool mInConn;
	wxArrayString* mInfoNames;
	bool mIsAE;
	bool mIsAwayMsg;
	wxString* mLastIP;
	wxString* mLastLog;
	wxString* mLastName;
	wxString* mLastPass;
	ChatlineSocket* mMainSock;
	bool mMsgBold;
	wxString* mMsgFont;
	bool mMsgItalic;
	unsigned int mMsgSize;
	bool mMsgUnd;
	wxString* mMyGender;
	wxString* mMyHob;
	short mMyIcon;
	wxString* mMyLoc;
	wxString* mMyMail;
	wxString* mMyName;
	wxString* mMyPCs;
	wxString* mMyQuote;
	wxString* mMySite;
	wxString* mNewsLoc;
	bool mNewsOpen;
	wxString* mNickAppend;
	bool mPlayCS;
	bool mPlayFD;
	bool mPlayGNS;
	bool mPlayLS;
	bool mPlayMS;
	bool mPlayUJ;
	bool mPlayUL;
	unsigned short mQueue;
	bool mRefusePM;
	bool mRefusePr;
	bool mServBanner;
	wxImage* mServerBannerPic;
	bool mShowJL;
	bool mSlimQueueCanvas;
	wxColour* mSysColor[];
	bool mTBClosed;
	wxString* mTrackerAddress;
	WindowTracker* mTrackerTracker;
	Privs* mUserPrivs;
	wxString* mUserWinPos;
	unsigned short mWindowMenuCount;
	
#ifdef __APPLE_CC__
	wxColour* DarkHighlightColor();
	void SetupPrefsMenu(wxString& text, wxString& key);
#endif

	void AddFileCache(wxString& path, wxString& data);
	void AddToChat(wxString& data, wxColour& clr);
	void BuildWindowMenu();
	void Caution(wxString& msg);
	short Caution3Buttons(wxString& msg, wxString& button1, wxString& button2, wxString& button3);
	void Center(wxWindow& window);
	wxImage* ChatlineLogo();
	void CloseAllFileTransfers();
	void CloseAllInfos();
	wxString* ConvertPicture(wxImage& p, bool newstyle);
	bool DoesTransferExist(wxString& id);
	void DoThemeSound(wxString& q);
	wxDir* DownloadFolder();
	void EditProfile();
	void EnableThem() {}
	void Fatal(wxString& msg);
	void FatalAdvanced(wxString& msg, wxString& littlemsg);
	bool FileCacheAvailable(wxString& path) const {return;} // incomplete
	unsigned short GetColorID(wxColour& c);
	wxString* GetFileCache(wxString& path) const {return;} // incomplete
	wxImage* GetFileFolderPic();
	TransferItem* GetFileTransfer(wxString& id);
	wxImage* GetFolderPic();
	wxString* GetFullRealNick() const {return Left(255);}
	unsigned short GetIDfromIndex(unsigned short d);
	unsigned short GetIndexFromID(unsigned short d);
	void GetNextInLine();
	wxImage* GetUploadFolderPic();
	bool HandleIRCCommand(wxString& cmd);
	void HiliteRect(int left, int top, unsigned short width, unsigned short height, bool Focus);
	void InitSysColorTable();
	void LoadPrefs();
	wxFile* MyAppFolderItem();
	void Note(wxString& msg);
	void OpenNewsCats();
	void ParseWinLocData(wxWindow& w, wxString& data, wxString& Default);
	wxString* PictureToString(wxImage& p);
	wxImage* RemakePicture(wxString& raw, bool newstyle);
	void RemoveFileTransfer(wxString& id);
	void RemoveInfoWindow(wxString& sock);
	void SavePrefs();
	void SetDefaults();
	void SetupWizard();
	wxString* ShortToString(short Short);
	void ShowFiles();
	wxString* SmallSystemFont() const;
	unsigned short SmallSystemSize() const;
	wxString* StringPlatformName() const;
	wxColour* StringToColor(wxString& s);
	double StringToDouble(wxString& Long);
	wxImage* StringToPicture(wxString& s);
	short StringToShort(wxString& Short);
	wxString* SysVers();
	unsigned int SysVersion();
	wxString* TicksToInterval(unsigned int TSX);
	
	virtual int OnExit();
	virtual bool OnInit();
	
	void OnInitDocument(wxFFile& item);
};

#endif