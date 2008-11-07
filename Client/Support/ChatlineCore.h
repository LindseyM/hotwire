#ifndef _CHATLINE_CORE_H_
#define _CHATLINE_CORE_H_

#include <wx/wx.h>
#include "../../shared/BaseProtocol.h"

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
	wxString* mAgreementStyl;
	bool mGettingServerName;
	wxString* mLastNickChange;
	wxString* mServerName;
	unsigned int mServerVersion;
	
	ChatlineSocket();
	~ChatlineSocket();

	virtual void CommandReceived(wxString& id, wxString& data, wxCommandEvent& event);
	virtual void Connected(wxCommandEvent& event);
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

	virtual void Disconnected(bool byServer, wxCommandEvent& event) = NULL;
	virtual bool DownloadServerBanner(, wxCommandEvent& event) = NULL;
	virtual void GetFile(wxString& Path, unsigned short Port, wxString& UID, wxCommandEvent& event) = NULL;
	virtual void GetProfile(unsigned short UserID, wxCommandEvent& event) = NULL;
	virtual bool GotAgreement(wxString& msg, wxString& styl, wxCommandEvent& event) = NULL;
	virtual void GotAwayMsg(wxString& sock, wxString& data, wxCommandEvent& event) = NULL;
	virtual void GotBroadcast(wxString& msg, wxCommandEvent& event) = NULL;
	virtual void GotChat(wxString& msg, wxCommandEvent& event) = NULL;
	virtual void GotColorChange(wxString& sock, wxColour& thecolor, wxCommandEvent& event) = NULL;
	virtual void GotFileList(wxString& Data, wxCommandEvent& event) = NULL;
	virtual void GotIconChange(wxString& sock, short newIcon, bool isCustom, wxString& customData,
		wxCommandEvent& event) = NULL;
	virtual void GotKilledCategory(wxString& catname, wxCommandEvent& event) = NULL;
	virtual void GotNameChange(wxString& sock, wxString& newName, wxCommandEvent& event) = NULL;
	virtual void GotNewsCategoriesList(wxString& list[], unsigned short count[],
		bool locked[], wxCommandEvent& event) = NULL;
	virtual void GotPrivateMsg(wxString& sock, wxString& msg, wxCommandEvent& event) = NULL;
	virtual void GotPrivs(Privs& thePrivs, wxCommandEvent& event) = NULL;
	virtual void GotServerBanner(wxImage& banner, wxCommandEvent& event) = NULL;
	virtual void GotServerInfo(wxString& name, wxString& speed, wxString& location,
		wxString& description, wxString& version, wxString& uptime, wxCommandEvent& event) = NULL;
	virtual void GotServerMsg(wxString& msg, wxCommandEvent& event) = NULL;
	virtual void GotServerName(wxString& name, wxCommandEvent& event) = NULL;
	virtual void GotUserInfo(unsigned short sock, wxString& info, wxCommandEvent& event) = NULL;
	virtual void GotUserList(UserList& UsrList, wxCommandEvent& event) = NULL;
	virtual void InvalidLogin(wxString& msg, wxCommandEvent& event) = NULL;
	virtual void InvPrivChat(unsigned short PChatID, unsigned short UserID, wxString& Topic,
		wxCommandEvent& event) = NULL;
	virtual void LoggedIn(, wxCommandEvent& event) = NULL;
	virtual void NewPrivChat(unsigned short PChatID, wxString& Topic, wxString& userList,
		wxCommandEvent& event) = NULL;
	virtual void PChatUserJoin(unsigned short PChatID, unsigned short UserID, wxCommandEvent& event) = NULL;
	virtual void PChatUserLeave(unsigned short PChatID, unsigned short UserID, wxCommandEvent& event) = NULL;
	virtual void PrivChat(unsigned short PChatID, wxString& Chat, wxCommandEvent& event) = NULL;
	virtual void PutFile(wxString& Path, unsigned short Port, wxString& UID, wxCommandEvent& event) = NULL;
	virtual void UnknownCommand(wxString& id, wxString& data, wxCommandEvent& event) = NULL;
	virtual void UserJoined(wxString& nick, short icon, unsigned short ID, wxColour& clr,
		bool iscustom, wxString& custom, wxCommandEvent& event) = NULL;
	virtual void UserLeft(unsigned short ID, wxCommandEvent& event) = NULL;
};

#endif