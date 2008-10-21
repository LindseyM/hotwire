#ifndef _FILE_MANAGEMENT_H_
#define _FILE_MANAGEMENT_H_

#include <wx/image.h>
#include <wx/string.h>
#include "TransferItem.h"

unsigned short DLGoing;
wxString* filenames[];

void AddFileCache(wxString* path, wxString* data);
void CloseAllFileTransfers();
bool DoesTransferExist(wxString* id);
bool FileCacheAvailable(wxString* path) const {return;}
wxString* GetFileCache(wxString* path) const {return;}
wxImage* GetFileFolderPic();
TransferItem* GetFileTransfer(wxString* id);
wxImage* GetFolderPic();
void GetNextInLine();
wxImage* GetUploadFolderPic();
void RemoveFileTransfer(wxString* id);

#endif