#ifndef SSH_CONNECT_H 
#define SSH_CONNECT_H

#include <wx/wx.h>

class sshConnect : public wxDialog {
	private:
		wxBoxSizer *verticalContentSizer;
		wxTextCtrl *userHostInput;
		wxTextCtrl *passwordInput;
		wxButton *submitButton;
		wxButton *cancelButton;
		void onCancel(wxCommandEvent& event);
		void onSubmit(wxCommandEvent& event);
		wxDECLARE_EVENT_TABLE();	
	public:
		sshConnect();
		~sshConnect();	
		wxString getUserHost();
		wxString getPass();
		
};


#endif // SSH_CONNECT_H
