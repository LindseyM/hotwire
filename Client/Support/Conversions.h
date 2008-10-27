#ifndef _CONVERSIONS_H_
#define _CONVERSIONS_H_

#include <wx/wx.h>

wxString* PictureToString(wxImage& p);
wxColour* StringToColor(wxString& s);
double StringToDouble(wxString& Long);
wxImage* StringToPicture(wxString& s);

#endif