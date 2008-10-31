#ifndef _BASE_P_SERVER_H_
#define _BASE_P_SERVER_H_

#include <wx/wx.h>
#include "../shared/BaseProtocol.h"
#include "Users/UserData.h"

class BasePServer: public BaseProtocol
{
public:
	BasePServer();
	~BasePServer();
	
	virtual void CommandReceived(wxString& id, wxString& data, wxCommandEvent& event);
	virtual void Connected(wxCommandEvent& event);
	void OnError(wxCommandEvent& event);
	void OnSendComplete(wxCommandEvent& event);
	void RemoveMeFromPChats();
	
	wxString* GetAddy() const								{return mAddy;}
	void SetAddy(wxString& s)								{mAddy = s;}
	bool GetAgreed() const									{return mAgreed;}
	void SetAgreed(bool b)									{mAgreed = b;}
	short GetIcon() const									{return mIcon;}
	void SetIcon(short n)									{mIcon = n;}
	wxString* GetIconData() const							{return mIconData;}
	void SetIconData(wxString& s)							{mIconData = s;}
	bool GetIsAway() const									{return mIsAway;}
	void SetIsAway(bool b)									{mIsAway = b;}
	bool GetKicked() const									{return mKicked;}
	void SetKicked(bool b)									{mKicked = b;}
	unsigned int* GetLast5ChatTimes() const					{return mLast5ChatTimes;}
	void SetLast5ChatTimes(unsigned int n1, unsigned int n2, unsigned int n3,
		unsigned int n4, unsigned int n5);
	bool GetLoggedIn() const								{return mLoggedIn;}
	void SetLoggedIn(bool b)								{mLoggedIn = b;}
	UserData* GetMyData() const								{return mMyData;}
	void SetMyData(UserData& o)								{mMyData = o;}
	wxString* GetNick() const								{return mNick;}
	void SetNick(wxString& s)								{mNick = s;}
	bool GetRefuseIMs() const								{return mRefuseIMs;}
	void SetRefuseIMs(bool b)								{mRefuseIMs = b;}
	bool GetRefusePChats() const							{return mRefusePChats;}
	void SetRefusePChats(bool b)							{mRefusePChats = b;}
	unsigned int GetSockID() const							{return mSockID;}
	void SetSockID(unsigned int n)							{mSockID = n;}
	wxString* GetStringVersion() const						{return mStringVersion;}
	void SetStringVersion(wxString& s)						{mStringVersion = s;}
	unsigned int GetVersion() const							{return mVersion;}
	void SetVersion(unsigned int n)							{mVersion = n;}
	bool GetWasUsed() const									{return mWasUsed;}
	void SetWasUsed(bool b)									{mWasUsed = b;}
private:
	wxString* mAddy;
	bool mAgreed;
	short mIcon;
	wxString* mIconData;
	bool mIsAway;
	bool mKicked;
	unsigned int mLast5ChatTimes[5];
	bool mLoggedIn;
	UserData* mMyData;
	wxString* mNick;
	bool mRefuseIMs;
	bool mRefusePChats;
	unsigned int mSockID;
	wxString* mStringVersion;
	unsigned int mVersion;
	bool mWasUsed;
};

#endif