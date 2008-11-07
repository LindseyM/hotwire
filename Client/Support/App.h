#ifndef _APP_H_
#define _APP_H_

#include <wx/wx.h>
#include "ChatlineCore.h"
#include "../Files/TransferItem.h"
#include "WindowTracker.h"

#define ALERT_CAUTION_ALERT				2
#define ALERT_DEFAULT_CANCEL_TEXT		1
#define ALERT_DEFAULT_OK_TEXT			-1
#define ALERT_DEFAULT_OTHER_TEXT		-1
#define ALERT_NOTE_TEXT					1
#define ALERT_PLAIN_TEXT				3
#define ALERT_STD_ALERT_CANCEL_BUTTON	2
#define ALERT_STD_ALERT_HELP_BUTTON		4
#define ALERT_STD_ALERT_OK_BUTTON		1
#define ALERT_STD_ALERT_OTHER_BUTTON	3
#define ALERT_STOP_ALERT				0
#define BUILD							"2008110601"
#define HELP_MANAGER_NOT_INITED			-855
#define MEM_FULL_ERR					-108
#define NO_ERR							0
#define PARAM_ERR						-50
#define RES_NOT_FOUND					-192
#define STD_ALERT_DEFAULT_TEXT			""
#define STD_ALERT_NO_BUTTON				"no button"

class App: public wxApp
{
public:
	wxString*			mAwayMsg;
	wxString*			mBlockedList;
	bool				mBookmarksOpen;
	wxString*			mCFont;
	bool				mChatWinOpen;
	wxString*			mChatWinPos;
	bool				mClearChat;
	unsigned int		mCSize;
	bool				mCustIcon;
	bool				mDidByMenu;
	unsigned short		mDLGoing;
	bool				mDLIC;
	wxString*			mDLLoc;
	wxString*			mDMLoc;
	bool				mDMOpen;
	bool				mDock;
	wxArrayString*		mFilenames;
	bool				mForceMsg;
	wxImage*			mIconPic;
	bool				mInConn;
	wxArrayString*		mInfoNames;
	bool				mIsAE;
	bool				mIsAwayMsg;
	wxString*			mLastIP;
	wxString*			mLastLog;
	wxString*			mLastName;
	wxString*			mLastPass;
	ChatlineSocket*		mMainSock;
	bool				mMsgBold;
	wxString*			mMsgFont;
	bool				mMsgItalic;
	unsigned int		mMsgSize;
	bool				mMsgUnd;
	wxString*			mMyGender;
	wxString*			mMyHob;
	short				mMyIcon;
	wxString*			mMyLoc;
	wxString*			mMyMail;
	wxString*			mMyName;
	wxString*			mMyPCs;
	wxString*			mMyQuote;
	wxString*			mMySite;
	wxString*			mNewsLoc;
	bool				mNewsOpen;
	wxString*			mNickAppend;
	bool				mPlayCS;
	bool				mPlayFD;
	bool				mPlayGNS;
	bool				mPlayLS;
	bool				mPlayMS;
	bool				mPlayUJ;
	bool				mPlayUL;
	unsigned short		mQueue;
	bool				mRefusePM;
	bool				mRefusePr;
	bool				mServBanner;
	wxImage*			mServerBannerPic;
	bool				mShowJL;
	bool				mSlimQueueCanvas;
	wxColour*			mSysColor[];
	bool				mTBClosed;
	wxString*			mTrackerAddress;
	WindowTracker*		mTrackerTracker;
	Privs*				mUserPrivs;
	wxString*			mUserWinPos;
	unsigned short		mWindowMenuCount;
	
#ifdef __APPLE_CC__
	wxColour*			DarkHighlightColor();
	void				SetupPrefsMenu(wxString& text, wxString& key);
#endif

	void				AddFileCache(wxString& path, wxString& data);
	void				AddToChat(wxString& data, wxColour& clr);
	void				BuildWindowMenu();
	void				Caution(wxString& msg);
	short				Caution3Buttons(wxString& msg, wxString& button1, wxString& button2,
							wxString& button3);
	void				Center(wxWindow& window);
	wxImage*			ChatlineLogo();
	void				CloseAllFileTransfers();
	void				CloseAllInfos();
	wxString*			ConvertPicture(wxImage& p, bool newstyle);
	bool				DoesTransferExist(wxString& id);
	void				DoThemeSound(wxString& q);
	wxDir*				DownloadFolder();
	void				EditProfile();
	void				EnableThem() {}
	void				Fatal(wxString& msg);
	void				FatalAdvanced(wxString& msg, wxString& littlemsg);
	bool				FileCacheAvailable(wxString& path) const {return;} // incomplete
	unsigned short		GetColorID(wxColour& c);
	wxString*			GetFileCache(wxString& path) const {return;} // incomplete
	wxImage*			GetFileFolderPic();
	TransferItem*		GetFileTransfer(wxString& id);
	wxImage*			GetFolderPic();
	wxString*			GetFullRealNick() const {return Left(255);}
	unsigned short		GetIDfromIndex(unsigned short d);
	unsigned short		GetIndexFromID(unsigned short d);
	void				GetNextInLine();
	wxImage*			GetUploadFolderPic();
	bool				HandleIRCCommand(wxString& cmd);
	void				HiliteRect(int left, int top, unsigned short width, unsigned short height,
							bool Focus);
	void				InitSysColorTable();
	void				LoadPrefs();
	wxFile*				MyAppFolderItem();
	void				Note(wxString& msg);
	void				OpenNewsCats();
	void				ParseWinLocData(wxWindow& w, wxString& data, wxString& Default);
	void				RemoveFileTransfer(wxString& id);
	void				RemoveInfoWindow(wxString& sock);
	void				SavePrefs();
	void				SetDefaults();
	void				SetupWizard();
	wxString*			ShortToString(short Short);
	void				ShowFiles();
	wxString*			SmallSystemFont() const;
	unsigned short		SmallSystemSize() const;
	int					StdAlert(int alertType, wxString& primaryText, wxString& secondaryText,
							wxString& defaultCaption, wxString& cancelCaption,
							wxString& otherCaption);
	wxString*			StringPlatformName() const;
	wxString*			SysVers();
	unsigned int		SysVersion();
	wxString*			TicksToInterval(unsigned int TSX);
	
	virtual int			OnExit();
	virtual bool		OnInit();
	void				OnInitDocument(wxFFile& item);
};

#endif