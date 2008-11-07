#ifndef _APP_H_
#define _APP_H_

#include <wx/wx.h>
#include "BasePServer.h"
#include "DeathThread.h"
#include "PrivateChat.h"
#include "UserData.h"
#include "XferListener.h"

#define BUILD			"2008110601"

class BlankIDException { };
class IllegalCastException { };
class NullObjectException { };
class OutOfBoundsException { };
class RuntimeException { };
class StackOverflowException { };
class TypeMismatchException { };

class App: public wxApp
{
protected:
	bool			mIsRunning;
public:
	bool			mAgreement;
	wxString*		mAgreementStyl;
	wxString*		mAgreementText;
	wxString*		mBanned;
	wxString*		mBannerLoc;
	short			mBasePort;
	BasePServer*	mBasePSocks[];
	bool			mConfirmQuit;
	wxString*		mDeft;
	bool			mDelNotTrash;
	DeathThread*	mDThr;
	bool			mDying;
	wxString*		mDynDNSHeader;
	wxString*		mDynDNSPassword;
	wxString*		mDynDNSUserID;
	BasePServer*	mErrorSock;
	wxString*		mGetIPHeader;
	wxString*		mHostname1;
	wxString*		mHostname2;
	wxString*		mHostname3;
	short			mIcon;
	bool			mInConn;
	wxString*		mInfoDesc;
	wxString*		mInfoLoc;
	wxString*		mInfoName;
	wxString*		mInfoSpeed;
	wxArrayString*	mIPsKicked;
	bool			mIsRoute;
	bool			mIsRouterAddress;
	bool			mIsStatic;
	wxString*		mLastDynDNSIP;
	UserData*		mMasterUsers[];
	unsigned short	mNumUserz;
	bool			mOneAtATime;
	unsigned short	mPChatID;
	wxArray*		mPChats;
	bool			mPlaySounds;
	short			mPortNumber;
	wxString*		mRealIP;
	bool			mRequireLogin;
	bool			mSaveLog;
	short			mSockNum;
	unsigned int	mStartTicks;
	wxString*		mTab;
	wxString*		mTrackerAddress;
	wxString*		mTrkrKey;
	bool			mUseDynDNS;
	wxDir*			mUsersFolder;
	XferListener*	mXferListen;
	
#ifdef __APPLE_CC__
	void			SetupPrefsMenu(wxString& text, wxString& key);
#endif

	void			AddToLog(wxString& ip, wxString& nick, wxString& crap);
	wxString*		Base64(wxString& s);
	bool			CanUpload(BasePServer& s, wxDir& f);
	void			Center(wxWindow& window);
	void			ClearKicked(wxString& ip);
	void			CloseConnection(unsigned short id);
	void			CloseServer();
	PrivateChat*	CreateNewPChat();
	wxDir*			DrillFilePath(wxString& path);
	void			FixSockUserData(UserData& oldud, UserData& newud);
	wxString*		FormatListItem(wxString& name, unsigned short percent);
	unsigned short	GetIDFromSock(BasePServer& sock);
	wxString*		GetNewPChatID();
	PrivateChat*	GetPChatByID(wxString& id);
	BasePServer*	GetSockFromID(unsigned short id);
	unsigned short	GetSockIndex(BasePServer& sock);
	void			HandleError(RuntimeException& err, wxString& where, wxString& etc);
	bool			IsServerRunning() const {return mIsRunning;}
	void			LoadUserFiles();
	void			MakeDynDNSUpdate();
	void			ProcessUser(BasePServer& sock);
	wxString*		PString(wxString& S);
	void			SendCmdToNotLoggedSock(BasePServer& sock, wxString& id, wxString& data);
	void			SendCommandToAll(wxString& id, wxString& data);
	void			SendCommandToNotSock(BasePServer& sock, wxString& id, wxString& data);
	void			SendCommandToNotSockID(unsigned int sock, wxString& id, wxString& data);
	void			SendCommandToSock(BasePServer& sock, wxString& id, wxString& data);
	void			SendCommandToSockID(unsigned int sock, wxString& id, wxString& data);
	wxString*		Spaces(int Num);
	wxString*		SPString(wxString& S);
	wxString*		StartServer(short pPort, bool rLogin);
	bool			WasKicked(wxString& ip);
	void			WriteDebug(wxString& debug);
	void			ZCommandReceived(BasePServer& sock, wxString& id, wxString& data);
	void			ZConnectionClosed(unsigned int id, bool closedByServer, bool wasLoggedIn,
						wxString& addy, BasePServer& sock);
	void			ZConnectionEstablished(BasePServer& sock);
	bool			ZLoginCommand(BasePServer& sock, wxString& id, wxString& data);
	//void			ZNewSocketListening(BasePServer& sock);
	//void			ZSendComplete(BasePServer& sock);
};

#endif