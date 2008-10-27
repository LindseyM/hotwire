#ifndef _BASE_PROTOCOL_H_
#define _BASE_PROTOCOL_H_

#include <wx/wx.h>

class BaseProtocol: public wxSocketBase
{
public:
	BaseProtocol();
	~BaseProtocol();

	void SendCommand(wxString& id, wxString& data);

	virtual void CommandReceived(wxString& id, wxString& data) = NULL;
	virtual void Connected() = NULL;
	
	wxString* GetData() const								{return mData;}
	void SetData(wxString& s)								{mData = s;}
	unsigned int GetDataLength() const						{return mDataLength;}
	void SetDataLength(unsigned int n)						{mDataLength = n;}
	bool GetGotData() const									{return mGotData;}
	void SetGotData(bool b)									{mGotData = b;}
	bool GetGotID() const									{return mGotID;}
	void SetGotID(bool b)									{mGotID = b;}
	bool GetGotLengths() const								{return mGotLengths;}
	void SetGotLengths(bool b)								{mGotLengths = b;}
	wxString* GetID() const									{return mID;}
	void SetID(wxString& s)									{mID = s;}
	unsigned int GetIDLength() const						{return mIDLength;}
	void SetIDLength(unsigned int n)						{mIDLength = n;}
	bool GetNewCommand() const								{return mNewCommand;}
	void SetNewCommand(bool b)								{mNewCommand = b;}
private:
	wxString* mData;
	unsigned int mDataLength;
	bool mGotData;
	bool mGotID;
	bool mGotLengths;
	wxString* mID;
	unsigned int mIDLength;
	bool mNewCommand;
};

#endif