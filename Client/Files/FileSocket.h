#ifndef _FILE_SOCKET_H_
#define _FILE_SOCKET_H_

#include <wx/wx.h>
#include "../Support/BaseProtocol.h"
#include "ResourceStream.h"

class FileSocket: public BaseProtocol
{
public:
	FileSocket();
	~FileSocket();

	virtual void CommandReceived(wxString& id, wxString& data);
	virtual void Connected();
	virtual void Error();
	unsigned int GetCurrentPosition();
	wxString* GetPlatform();
	double GetSpeed();
	virtual void SendComplete();

	virtual void FileReceived(wxFile& file) = NULL;
	virtual void FileSent(wxFile& file) = NULL;
	virtual void GotPlatform() = NULL;
	virtual void PacketSizeChanged(unsigned int packetSize) = NULL;
	virtual void Progress(unsigned short percent, unsigned int speed, unsigned short done,
		unsigned long total) = NULL;
	virtual void QueueStatus(unsigned int LineNum, unsigned short WhichQueue) = NULL;
	virtual void RawError(int code) = NULL;
	virtual void TransferError(wxString& message) = NULL;
	virtual void TransferStarted(wxFile& file, bool isReceiving) = NULL;
	virtual void TransferStopped(wxFile& file) = NULL;

	bool GetDataForkOnly() const						{return mDataForkOnly;}
	void SetDataForkOnly(bool b)						{mDataForkOnly = b;}
	wxFile* GetDesiredFile() const						{return mDesiredFile;}
	void SetDesiredFile(wxFile& o)						{mDesiredFile = o;}
	int GetErr() const									{return mErr;}
	void SetErr(int n)									{mErr = n;}
	wxFileStream* GetFileStream() const					{return mFileStream;}
	void SetFileStream(wxFileStream& o)					{mFileStream = o;}
	bool GetIsConnected() const							{return mIsConnected;}
	void SetIsConnected(bool b)							{mIsConnected = b;}
	bool GetIsSender() const							{return mIsSender;}
	void SetIsSender(bool b)							{mIsSender = b;}
	bool GetIsSending() const							{return mIsSending;}
	void SetIsSending(bool b)							{mIsSending = b;}
	unsigned int GetLastSize() const					{return mLastSize;}
	void SetLastSize(unsigned int n)					{mLastSize = n;}
	unsigned int GetMaxSize() const						{return mMaxSize;}
	void SetMaxSize(unsigned int n)						{mMaxSize = n;}
	bool GetMaySendData() const							{return mMaySendData;}
	void SetMaySendData(bool b)							{mMaySendData = b;}
	unsigned short GetMode() const						{return mMode;}
	void SetMode(unsigned short n)						{mMode = n;}
	double GetOtherVersion() const						{return mOtherVersion;}
	void SetOtherVersion(double f)						{mOtherVersion = f;}
	unsigned int GetPacketSize() const					{return mPacketSize;}
	void SetPacketSize(unsigned int n)					{mPacketSize = n;}
	void SetPlatform(wxString& s)						{mPlatform = s;}
	unsigned int GetResLength() const					{return mResLength;}
	void SetResLength(unsigned int n)					{mResLength = n;}
	ResourceStream* GetResStream() const				{return mResStream;}
	void SetResStream(ResourceStream& o)				{mResStream = o;}
	unsigned int GetResSubt() const						{return mResSubt;}
	void SetResSubt(unsigned int n)						{mResSubt = n;}
	double GetTime() const								{return mTime;}
	void SetTime(double f)								{mTime = f;}
	wxString* GetUID() const							{return mUID;}
	void SetUID(wxString& s)							{mUID = s;}
	bool GetUploading() const							{return mUploading;}
	void SetUploading(bool b)							{mUploading = b;}
private:
	bool mDataForkOnly;
	wxFile* mDesiredFile;
	int mErr;
	wxFileStream* mFileStream;
	bool mIsConnected;
	bool mIsSender;
	bool mIsSending;
	unsigned int mLastSize;
	unsigned int mMaxSize;
	bool mMaySendData;
	unsigned short mMode;
	double mOtherVersion;
	unsigned int mPacketSize;
	wxString* mPlatform;
	unsigned int mResLength;
	ResourceStream* mResStream;
	unsigned int mResSubt;
	double mTime;
	wxString* mUID;
	bool mUploading;
};

#endif