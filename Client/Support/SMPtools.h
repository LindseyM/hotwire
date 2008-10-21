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
wxString* blockedList;
bool BookmarksOpen;
wxString* cfont;
bool Clearchat;
unsigned int csize;
bool custicon;
bool DLIC;
wxString* DLLoc;
wxString* DMLoc;
bool DMopen;
bool dock;
bool forcemsg;
wxImage* IconPic;
bool inconn;
bool isAE;
bool isAwayMsg;
wxString* lastIP;
wxString* lastlog;
wxString* lastName;
wxString* lastpass;
ChatlineSocket* MainSock;
bool msgbold;
wxString* msgfont;
bool msgitalic;
unsigned int msgsize;
bool msgund;
wxString* myGender;
wxString* myHob;
short myIcon;
wxString* myLoc;
wxString* myMail;
wxString* myName;
wxString* myPCs;
wxString* myQuote;
wxString* mysite;
wxString* NewsLoc;
bool NewsOpen;
wxString* NickAppend;
bool playcs;
bool playfd;
bool playgns;
bool playls;
bool playms;
bool PlayUJ;
bool PlayUL;
short queue;
bool RefusePM;
bool refusepr;
bool servbanner;
bool ShowJL;
bool TBClosed;
Privs* UserPrivs;
wxString* UserWinPos;

void Caution(wxString* msg);
short Caution3Buttons(wxString* msg, wxString* button1, wxString* button2, wxString* button3);
void Center(wxWindow* window);
wxDir* DownloadFolder();
void EditProfile();
void Fatal(wxString* msg);
void FatalAdvanced(wxString* msg, wxString* littlemsg);
wxString* GetFullRealNick() const {return Left(255);}
bool HandleIRCCommand(wxString* cmd);
wxFile* MyAppFolderItem();
void Note(wxString* msg);
void OpenNewsCats();
void SavePrefs();
void ShowFiles();
wxString* StringPlatformName() const;
unsigned int SysVersion();

#endif