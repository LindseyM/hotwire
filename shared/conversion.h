#ifndef _CONVERSION_H_
#define _CONVERSION_H_

#include <wx/wx.h>

#define BOOL_TO_CHAR(b)		(b)?'y':'n'
#define BOOL_TO_INT(b)		(b)?1:0
#define BOOL_TO_STRING(b)	(b)?"true":"false"
#define CHAR_TO_BOOL(text)	(text)=='y'
#define INT_TO_BOOL(i)		(i)==1

wxString*		DoubleToString(double number);
wxString*		PictureToString(wxImage& p);
wxImage*		RemakePicture(wxString& raw, bool newstyle);
wxString*		ShortToString(short Short);
wxColour*		StringToColor(wxString& s);
unsigned double	StringToDouble(wxString& Long);
wxImage*		StringToPicture(wxString& s);
unsigned short	StringToShort(wxString& Short);

#endif