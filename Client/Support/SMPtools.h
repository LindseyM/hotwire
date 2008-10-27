#ifndef _SMPTOOLS_H_
#define _SMPTOOLS_H_

#include <wx/dir.h>
#include <wx/file.h>
#include <wx/image.h>
#include <wx/string.h>
#include <wx/window.h>

#include "ChatlineCore.h"

#define BoolToChar(b) (b)?'y':'n'
#define BoolToInt(b) (b)?1:0
#define BoolToString(b) (b)?"true":"false"
#define IntToBool(i) (i)==1
#define CharToBool(text) (text)=='y'

wxString* AwayMsg;
wxString* BlockedList;
bool BookmarksOpen;
wxString* CFont;
bool ClearChat;
unsigned int CSize;
bool CustIcon;
bool DLIC;
wxString* DLLoc;
wxString* DMLoc;
bool DMOpen;
bool Dock;
bool ForceMsg;
wxImage* IconPic;
bool InConn;
bool IsAE;
bool IsAwayMsg;
wxString* LastIP;
wxString* LastLog;
wxString* LastName;
wxString* LastPass;
ChatlineSocket* MainSock;
bool MsgBold;
wxString* MsgFont;
bool MsgItalic;
unsigned int MsgSize;
bool MsgUnd;
wxString* MyGender;
wxString* MyHob;
short MyIcon;
wxString* MyLoc;
wxString* MyMail;
wxString* MyName;
wxString* MyPCs;
wxString* MyQuote;
wxString* MySite;
wxString* NewsLoc;
bool NewsOpen;
wxString* NickAppend;
bool PlayCS;
bool PlayFD;
bool PlayGNS;
bool PlayLS;
bool PlayMS;
bool PlayUJ;
bool PlayUL;
short Queue;
bool RefusePM;
bool RefusePr;
bool ServBanner;
bool ShowJL;
bool TBClosed;
Privs* UserPrivs;
wxString* UserWinPos;

void Caution(wxString& msg);
short Caution3Buttons(wxString& msg, wxString& button1, wxString& button2, wxString& button3);
void Center(wxWindow& window);
wxDir* DownloadFolder();
void EditProfile();
void Fatal(wxString& msg);
void FatalAdvanced(wxString& msg, wxString& littlemsg);
wxString* GetFullRealNick() const {return Left(255);}
bool HandleIRCCommand(wxString& cmd);
wxFile* MyAppFolderItem();
void Note(wxString& msg);
void OpenNewsCats();
void SavePrefs();
void ShowFiles();
wxString* StringPlatformName() const;
unsigned int SysVersion();

#endif