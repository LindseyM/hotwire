#ifndef _BASE_PROTOCOL_H_
#define _BASE_PROTOCOL_H_

#include <wx/wx.h>

class BaseProtocol: public wxSocketBase
{
protected:
	wxString*		mData;
	unsigned int	mDataLength;
	bool			mGotData;
	bool			mGotID;
	bool			mGotLengths;
	wxString*		mID;
	unsigned int	mIDLength;
	bool			mNewCommand;
public:
	BaseProtocol();
	~BaseProtocol();

	void			SendCommand(wxString& id, wxString& data);
	
	void			OnConnected(wxCommandEvent& event);
	void			OnDataAvailable(wxCommandEvent& event);

	virtual void	CommandReceived(wxString& id, wxString& data) = NULL;
	virtual void	Connected() = NULL;
};

#endif