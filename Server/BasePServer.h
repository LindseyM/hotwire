#ifndef _BASE_P_SERVER_H_
#define _BASE_P_SERVER_H_

#include <wx/wx.h>
#include "../shared/BaseProtocol.h"
#include "Users/UserData.h"

class BasePServer: public BaseProtocol
{
public:
	wxString*		mAddy;
	bool			mAgreed;
	short			mIcon;
	wxString*		mIconData;
	bool			mIsAway;
	bool			mKicked;
	unsigned int	mLast5ChatTimes[5];
	bool			mLoggedIn;
	UserData*		mMyData;
	wxString*		mNick;
	bool			mRefuseIMs;
	bool			mRefusePChats;
	unsigned int	mSockID;
	wxString*		mStringVersion;
	unsigned int	mVersion;
	bool			mWasUsed;
	
	BasePServer();
	~BasePServer();
	
	virtual void	CommandReceived(wxString& id, wxString& data);
	virtual void	Connected();
	void			RemoveMeFromPChats();
	
	void			OnError(wxCommandEvent& event);
	void			OnSendComplete(wxCommandEvent& event);
};

#endif