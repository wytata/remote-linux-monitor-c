#ifndef SSH_CONNECT_H 
#define SSH_CONNECT_H

#include <wx/wx.h>

class sshConnect : public wxDialog {
	private:
		wxTextCtrl *userHostInput;
		wxTextCtrl *passwordInput;
		wxButton *submitButton;
		wxButton *cancelButton;
		void onCancel(wxCommandEvent& event);
		wxDECLARE_EVENT_TABLE();	
	public:
		sshConnect();
		~sshConnect();	
		
};


#endif // !DEBUG
