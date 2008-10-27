#ifndef _CHATLINE_CORE_H_
#define _CHATLINE_CORE_H_

#include <wx/wx.h>
#include "BaseProtocol.h"

struct Privs
{
	bool Ban,
		 Broadcast,
		 CanLockUnlockNews,
		 DelCat,
		 Exempt,
		 FilesCreateFolder,
		 FilesDelete,
		 FilesDownload,
		 FilesEditInfo,
		 FilesSeeList,
		 FilesUpload,
		 FilesUploadAnywhere,
		 GetInfo,
		 Kick,
		 MakeCat,
		 PostNews,
		 ReadChat,
		 ReadNews,
		 SendChat,
		 SendMsg,
		 ServInfo;
};

struct User
{
	wxString* CustomDat;
	short Icon;
	short ID;
	bool IsCustom;
	wxString* Nick;
	wxColour* Color;
};

struct UserList
{
	short NumUsers;
	User* Users[];
};

class ChatlineSocket: public BaseProtocol
{
public:
	ChatlineSocket();
	~ChatlineSocket();

	virtual void CommandReceived(wxString& id, wxString& data);
	virtual void Connected();
	void Disconnect();
	void GetProfile(unsigned short UserID);
	void HaveBanner(wxImage& p);
	void InvPrivChat(unsigned short PChatID, unsigned short UserID);
	void KickOrBanUser(unsigned short user);
	void PChatLeave(unsigned short PChatID);
	void PrivEmote(unsigned short PChatID, wxString& emote);
	UserList* ProcessUserList(wxString& data);
	void RequestAwayMsg(wxString& sock, wxString& data);
	void RequestChangeNick(wxString& newnick);
	void RequestCreatePChat(unsigned short IDs[], wxString& Topic);
	void RequestGetInfo(wxString& sock);
	void RequestSendMsg(wxString& sock, wxString& data);
	void RequestServerInfo();
	void SendMsgEmote(wxString& sock, wxString& data);
	wxColour* StringToColor(wxString& s);

	virtual void Disconnected(bool byServer) = NULL;
	virtual bool DownloadServerBanner() = NULL;
	virtual void GetFile(wxString& Path, unsigned short Port, wxString& UID) = NULL;
	virtual void GetProfile(unsigned short UserID) = NULL;
	virtual bool GotAgreement(wxString& msg, wxString& styl) = NULL;
	virtual void GotAwayMsg(wxString& sock, wxString& data) = NULL;
	virtual void GotBroadcast(wxString& msg) = NULL;
	virtual void GotChat(wxString& msg) = NULL;
	virtual void GotColorChange(wxString& sock, wxColour& thecolor) = NULL;
	virtual void GotFileList(wxString& Data) = NULL;
	virtual void GotIconChange(wxString& sock, short newIcon, bool isCustom, wxString& customData) = NULL;
	virtual void GotKilledCategory(wxString& catname) = NULL;
	virtual void GotNameChange(wxString& sock, wxString& newName) = NULL;
	virtual void GotNewsCategoriesList(wxString& list[], unsigned short count[],
		bool locked[]) = NULL;
	virtual void GotPrivateMsg(wxString& sock, wxString& msg) = NULL;
	virtual void GotPrivs(Privs& thePrivs) = NULL;
	virtual void GotServerBanner(wxImage& banner) = NULL;
	virtual void GotServerInfo(wxString& name, wxString& speed, wxString& location,
		wxString& description, wxString& version, wxString& uptime) = NULL;
	virtual void GotServerMsg(wxString& msg) = NULL;
	virtual void GotServerName(wxString& name) = NULL;
	virtual void GotUserInfo(unsigned short sock, wxString& info) = NULL;
	virtual void GotUserList(UserList& UsrList) = NULL;
	virtual void InvalidLogin(wxString& msg) = NULL;
	virtual void InvPrivChat(unsigned short PChatID, unsigned short UserID, wxString& Topic) = NULL;
	virtual void LoggedIn() = NULL;
	virtual void NewPrivChat(unsigned short PChatID, wxString& Topic, wxString& userList) = NULL;
	virtual void PChatUserJoin(unsigned short PChatID, unsigned short UserID) = NULL;
	virtual void PChatUserLeave(unsigned short PChatID, unsigned short UserID) = NULL;
	virtual void PrivChat(unsigned short PChatID, wxString& Chat) = NULL;
	virtual void PutFile(wxString& Path, unsigned short Port, wxString& UID) = NULL;
	virtual void UnknownCommand(wxString& id, wxString& data) = NULL;
	virtual void UserJoined(wxString& nick, short icon, unsigned short ID, wxColour& clr,
		bool iscustom, wxString& custom) = NULL;
	virtual void UserLeft(unsigned short ID) = NULL;
	
	wxString* GetAgreementStyl() const						{return mAgreementStyl;}
	void SetAgreementStyl(wxString& s)						{mAgreementStyl = s;}
	bool GetGettingServerName() const						{return mGettingServerName;}
	void SetGettingServerName(bool b)						{mGettingServerName = b;}
	wxString* GetLastNickChange() const						{return mLastNickChange;}
	void SetLastNickChange(wxString& s)						{mLastNickChange = s;}
	wxString* GetServerName() const							{return mServerName;}
	void SetServerName(wxString* s)							{mServerName = s;}
	unsigned int GetServerVersion() const					{return mServerVersion;}
	void SetServerVersion(unsigned int n)					{mServerVersion = n;}
private:
	wxString* mAgreementStyl;
	bool mGettingServerName;
	wxString* mLastNickChange;
	wxString* mServerName;
	unsigned int mServerVersion;
};

#endif