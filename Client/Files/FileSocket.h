#ifndef _FILE_SOCKET_H_
#define _FILE_SOCKET_H_

#include <wx/wx.h>
#include "../../shared/BaseProtocol.h"
#include "ResourceStream.h"

class FileSocket: public BaseProtocol
{
public:
	bool				mDataForkOnly;
	wxFile*				mDesiredFile;
	int					mErr;
	wxFileStream*		mFileStream;
	bool				mIsConnected;
	bool				mIsSender;
	bool				mIsSending;
	unsigned int		mLastSize;
	unsigned int		mMaxSize;
	bool				mMaySendData;
	unsigned short		mMode;
	double				mOtherVersion;
	unsigned int		mPacketSize;
	wxString*			mPlatform;
	unsigned int		mResLength;
	ResourceStream*		mResStream;
	unsigned int		mResSubt;
	double				mTime;
	wxString*			mUID;
	bool				mUploading;

	FileSocket();
	~FileSocket();

	virtual void		CommandReceived(wxString& id, wxString& data);
	virtual void		Connected();
	virtual void		Error();
	unsigned int		GetCurrentPosition();
	wxString*			GetPlatform();
	double				GetSpeed();
	virtual void		SendComplete();

	virtual void		FileReceived(wxFile& file) = NULL;
	virtual void		FileSent(wxFile& file) = NULL;
	virtual void		GotPlatform() = NULL;
	virtual void		PacketSizeChanged(unsigned int packetSize) = NULL;
	virtual void		Progress(unsigned short percent, unsigned int speed, unsigned short done,
							unsigned long total) = NULL;
	virtual void		QueueStatus(unsigned int LineNum, unsigned short WhichQueue) = NULL;
	virtual void		RawError(int code) = NULL;
	virtual void		TransferError(wxString& message) = NULL;
	virtual void		TransferStarted(wxFile& file, bool isReceiving) = NULL;
	virtual void		TransferStopped(wxFile& file) = NULL;
};

#endif