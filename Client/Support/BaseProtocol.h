#ifndef _BASE_PROTOCOL_H_
#define _BASE_PROTOCOL_H_

#include <wx/socket.h>
#include <wx/string.h>

class BaseProtocol: public wxSocketBase
{
protected:
	wxString* data;
	unsigned int dataLength;
	bool gotData;
	bool gotID;
	bool gotLengths;
	wxString* id;
	unsigned int idLength;
	bool newCommand;
public:
	BaseProtocol();
	~BaseProtocol();

	void sendCommand(wxString* pID, wxString* pData);

	virtual void commandReceived(wxString* pID, wxString* pData) = NULL;
	virtual void connected() = NULL;
};

#endif