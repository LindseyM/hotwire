#ifndef _CONTROLS_H_
#define _CONTROLS_H_

#include <wx/string.h>
#include "WindowTracker.h"

#define BUILD "1B26"

WindowTracker* TrackerTracker;

void HiliteRect(int left, int top, unsigned short width, unsigned short height, bool Focus);
wxString* ShortToString(short Short);
short StringToShort(wxString& Short);
wxString* TicksToInterval(unsigned int TSX);

#endif