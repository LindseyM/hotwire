#ifndef _INFO_MANAGEMENT_H_
#define _INFO_MANAGEMENT_H_

#include <wx/string.h>

wxString* infonames[];

void CloseAllInfos();
void RemoveInfoWindow(wxString* sock);

#endif