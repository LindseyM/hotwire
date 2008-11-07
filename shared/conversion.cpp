#include <wx/wx.h>
#include "conversion.h"

wxString* DoubleToString(double number)
{
}

/*
wxString* PictureToString(wxImage& p)
{
	wxClipboard* c;
	wxString* s;
	
	if (p != NULL)
	{
		c = new wxClipboard();
		c->Open();
		c->GetData(p);
		c->Close();
	}
}
*/

wxImage*  RemakePicture(wxString& raw, bool newstyle)
{
}

wxString* ShortToString(short Short)
{
}

wxColour* StringToColor(wxString& s)
{
}

unsigned double StringToDouble(wxString& Long)
{
	return Long->GetChar(Long->Left(1)) * 16777216.0 +
		Long->GetChar(Long->Mid(2,1)) * 65536 +
		Long->GetChar(Long->Mid(3,1)) * 256 +
		Long->GetChar(Long->Right(1));
}

wxImage* StringToPicture(wxString& s)
{
}

unsigned short StringToShort(wxString& Short)
{
}