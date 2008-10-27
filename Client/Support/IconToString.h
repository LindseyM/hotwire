#ifndef _ICON_TO_STRING_H_
#define _ICON_TO_STRING_H_

#include <wx/colour.h>
#include <wx/image.h>
#include <wx/string.h>

wxColour* SysColor[];

wxString* ConvertPicture(wxImage& p, bool newstyle);
unsigned short GetColorID(wxColour& c);
void InitSysColorTable();
wxImage* RemakePicture(wxString& raw, bool newstyle);

#endif