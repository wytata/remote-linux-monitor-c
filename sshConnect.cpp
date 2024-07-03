#include "sshConnect.h"

wxBEGIN_EVENT_TABLE(sshConnect, wxDialog)
    EVT_BUTTON(69, sshConnect::onCancel)
wxEND_EVENT_TABLE()

void sshConnect::onCancel(wxCommandEvent& event) {
    Close(true);
}

sshConnect::sshConnect() : wxDialog(nullptr, wxID_ANY, "SSH Login") {
    int width, height;
    GetSize(&width, &height);

    std::cout << "Size of parent window is " << width << " by " << height << std::endl;
    userHostInput = new wxTextCtrl(this, -1, "", wxPoint(width/4, height/2-30), wxSize(width/2,height/10));
    passwordInput = new wxTextCtrl(this, -1, "", wxPoint(width/4, height/2+30), wxSize(width/2,height/10), wxTE_PASSWORD);

    wxSize defaultButtonSize = wxButton::GetDefaultSize();
    submitButton = new wxButton(this, -1, "Submit", wxPoint(5, height-defaultButtonSize.GetHeight()-10));
    cancelButton = new wxButton(this, 69, "Cancel", wxPoint(width - defaultButtonSize.GetWidth()-5, height-defaultButtonSize.GetHeight()-10));


}

sshConnect::~sshConnect() {
    delete userHostInput;
    delete passwordInput;
}
