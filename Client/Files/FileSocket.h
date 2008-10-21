#ifndef _FILE_SOCKET_H_
#define _FILE_SOCKET_H_

#include <wx/file.h>
#include <wx/string.h>
#include <wx/wfstrem.h>
#include "../Support/BaseProtocol.h"
#include "ResourceStream.h"

class FileSocket: public BaseProtocol
{
protected:
	bool dataForkOnly;
	wxFileStream* fileStream;
	unsigned int lastSize;
	unsigned int resLength;
	ResourceStream* resStream;
	double time;
public:
	wxFile* desiredfile;
	int err;
	bool isConnected;
	bool isSender;
	bool isSending;
	unsigned int maxSize;
	bool MaySendData;
	unsigned short mode;
	double OtherVersion;
	unsigned int packetSize;
	wxString* platform;
	unsigned int resSubt;
	wxString* UID;
	bool uploading;

	FileSocket();
	~FileSocket();

	virtual void commandReceived(wxString* id, wxString* data);
	virtual void connected();
	virtual void Error();
	unsigned int getCurrentPosition();
	wxString* getPlatform();
	double getSpeed();
	virtual void SendComplete();

	virtual void FileReceived(wxFile* file) = NULL;
	virtual void FileSent(wxFile* file) = NULL;
	virtual void GotPlatform() = NULL;
	virtual void PacketSizeChanged(unsigned int PacketSize) = NULL;
	virtual void Progress(unsigned short percent, unsigned int speed, unsigned short done, unsigned long total) = NULL;
	virtual void QueueStatus(unsigned int LineNum, unsigned short WhichQueue) = NULL;
	virtual void RawError(int code) = NULL;
	virtual void TransferError(wxString* message) = NULL;
	virtual void TransferStarted(wxFile* file, bool isReceiving) = NULL;
	virtual void TransferStopped(wxFile* file) = NULL;
};

#endif