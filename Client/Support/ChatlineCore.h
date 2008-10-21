#ifndef _CHATLINE_CORE_H_
#define _CHATLINE_CORE_H_

#include <wx/colour.h>
#include <wx/image.h>
#include <wx/string.h>
#include "BaseProtocol.h"

struct Privs
{
	bool ban,
		 broadcast,
		 canlockunlocknews,
		 delcat,
		 exempt,
		 filescreatefolder,
		 FilesDelete,
		 Filesdownload,
		 fileseditinfo,
		 FilesSeeList,
		 filesupload,
		 filesuploadanywhere,
		 getinfo,
		 Kick,
		 makecat,
		 postnews,
		 readchat,
		 readnews,
		 sendchat,
		 sendmsg,
		 servinfo;
};

struct User
{
	wxString* CustomDat;
	short icon;
	short pID;
	bool isCustom;
	wxString* nick;
	wxColour* color;
};

struct UserList
{
	short NumUsers;
	User* users[];
};

class ChatlineSocket: public BaseProtocol
{
public:
	wxString* AgreementStyl;
	bool GettingServerName;
	wxString* LastNickChange;
	wxString* ServerName;
	unsigned int ServerVersion;

	ChatlineSocket();
	~ChatlineSocket();

	virtual void commandReceived(wxString* pID, wxString* pData);
	virtual void connected();
	void Disconnect();
	void GetProfile(unsigned short UserID);
	void HaveBanner(wxImage* p);
	void InvPrivChat(unsigned short PChatID, unsigned short UserID);
	void KickOrBanUser(unsigned short user);
	void PChatLeave(unsigned short PChatID);
	void PrivEmote(unsigned short PChatID, wxString* emote);
	UserList* ProcessUserList(wxString* pData);
	void RequestAwayMsg(wxString* sock, wxString* pData);
	void RequestChangeNick(wxString* newnick);
	void RequestCreatePChat(unsigned short IDs[], wxString* Topic);
	void RequestGetInfo(wxString* sock);
	void RequestSendMsg(wxString* sock, wxString* pData);
	void RequestServerInfo();
	void SendMsgEmote(wxString* sock, wxString* pData);
	wxColour* StringToColor(wxString* s);

	virtual void Disconnected(bool byServer) = NULL;
	virtual bool DownloadServerBanner() = NULL;
	virtual void GetFile(wxString* Path, unsigned short Port, wxString* UID) = NULL;
	virtual void GetProfile(unsigned short UserID) = NULL;
	virtual bool GotAgreement(wxString* msg, wxString* styl) = NULL;
	virtual void GotAwayMsg(wxString* sock, wxString* pData) = NULL;
	virtual void GotBroadcast(wxString* msg) = NULL;
	virtual void GotChat(wxString* msg) = NULL;
	virtual void GotColorChange(wxString* sock, wxColour* thecolor) = NULL;
	virtual void GotFileList(wxString* Data) = NULL;
	virtual void GotIconChange(wxString* sock, short newIcon, bool isCustom, wxString* customData) = NULL;
	virtual void GotKilledCategory(wxString* catname) = NULL;
	virtual void GotNameChange(wxString* sock, wxString* newName) = NULL;
	virtual void GotNewsCategoriesList(wxString* list[], unsigned short count[], bool locked[]) = NULL;
	virtual void GotPrivateMsg(wxString* sock, wxString* msg) = NULL;
	virtual void GotPrivs(Privs* thePrivs) = NULL;
	virtual void GotServerBanner(wxImage* banner) = NULL;
	virtual void GotServerInfo(wxString* name, wxString* speed, wxString* location, wxString* description,
		wxString* version, wxString* uptime) = NULL;
	virtual void GotServerMsg(wxString* msg) = NULL;
	virtual void GotServerName(wxString* name) = NULL;
	virtual void GotUserInfo(unsigned short sock, wxString* info) = NULL;
	virtual void GotUserList(UserList* UsrList) = NULL;
	virtual void InvalidLogin(wxString* msg) = NULL;
	virtual void InvPrivChat(unsigned short PChatID, unsigned short UserID, wxString* Topic) = NULL;
	virtual void LoggedIn() = NULL;
	virtual void NewPrivChat(unsigned short PChatID, wxString* Topic, wxString* userList) = NULL;
	virtual void PChatUserJoin(unsigned short PChatID, unsigned short UserID) = NULL;
	virtual void PChatUserLeave(unsigned short PChatID, unsigned short UserID) = NULL;
	virtual void PrivChat(unsigned short PChatID, wxString* Chat) = NULL;
	virtual void PutFile(wxString* Path, unsigned short Port, wxString* UID) = NULL;
	virtual void UnknownCommand(wxString* pID, wxString* pData) = NULL;
	virtual void UserJoined(wxString* nick, short icon, unsigned short ID, wxColour* clr, bool iscustom,
		wxString* custom) = NULL;
	virtual void UserLeft(unsigned short ID) = NULL;
};

#endif