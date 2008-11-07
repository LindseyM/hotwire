#ifndef _CC_STD_ALERT_H_
#define _CC_STD_ALERT_H_

#include <wx/wx.h>

#define HM_HELP_MANAGER_NOT_INITED -855
#define K_ALERT_CAUTION_ALERT 2
#define K_ALERT_DEFAULT_CANCEL_TEXT 1
#define K_ALERT_DEFAULT_OK_TEXT -1
#define K_ALERT_DEFAULT_OTHER_TEXT -1
#define K_ALERT_NOTE_TEXT 1
#define K_ALERT_PLAIN_TEXT 3
#define K_ALERT_STD_ALERT_CANCEL_BUTTON 2
#define K_ALERT_STD_ALERT_HELP_BUTTON 4
#define K_ALERT_STD_ALERT_OK_BUTTON 1
#define K_ALERT_STD_ALERT_OTHER_BUTTON 3
#define K_ALERT_STOP_ALERT 0
#define MEM_FULL_ERR -108
#define NO_ERR 0
#define PARAM_ERR -50
#define RES_NOT_FOUND -192
#define STD_ALERT_DEFAULT_TEXT ""
#define STD_ALERT_NO_BUTTON "no button"

int StdAlert(int alertType, wxString& primaryText, wxString& secondaryText, wxString& defaultCaption,
	wxString& cancelCaption, wxString& otherCaption);

#endif