#ifndef _RESOURCE_STREAM_H_
#define _RESOURCE_STREAM_H_

#include <wx/wx.h>

class ResourceStream
{
public:
	unsigned int	mRefNum;

	ResourceStream();
	~ResourceStream();

	void			Close();
	bool			EOF();
	unsigned int	GetLength();
	int				GetPosition();
	bool			IsOpen();
	wxString*		Read(unsigned int bytes);
	wxString*		ReadAll();
	void			SetFile(wxFFile& file);
	void			SetLength(unsigned int length);
	void			SetPosition(unsigned int pos);
	void			Write(wxString& data);
};

#endif