#include "sshConnect.h"
#include "libssh/libsshpp.hpp"
#include <algorithm>
#include <string>
#include <iostream>
#include <libssh/libssh.h>

wxBEGIN_EVENT_TABLE(sshConnect, wxDialog)
    EVT_BUTTON(71, sshConnect::onCancel)
    EVT_BUTTON(70, sshConnect::onSubmit)
wxEND_EVENT_TABLE()

void sshConnect::onCancel(wxCommandEvent& event) {
    Close(true);
}

void sshConnect::onSubmit(wxCommandEvent& event) {
    // get creds and create an ssh sesh
    std::string userHost, password;
    userHost = getUserHost();
    password = getPass();
    std::size_t userHostSeparator = userHost.find("@");
    std::string user = userHost.substr(0, userHostSeparator);
    std::string host = userHost.substr(userHostSeparator+1);

    std::cout << "Connecting user " << user << " with password " << password << " to host " << host << std::endl;

    ssh_session sesh = ssh_new();
    if (sesh == NULL) {
        ssh_free(sesh);
        printf("SESSION IS NULL\n");
        return;
    }

    int port = 22;
    int verbosity = SSH_LOG_PROTOCOL;
    ssh_options_set(sesh, SSH_OPTIONS_HOST, host.c_str());
    ssh_options_set(sesh, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
    ssh_options_set(sesh, SSH_OPTIONS_PORT, &port);

    int rc = ssh_connect(sesh);
    if (rc != SSH_OK) {
        printf("SSH CONNECT RETURNED NOT OK SESSION\n");
        ssh_free(sesh);
        return;
    }

    // TODO Authenticate the server

    ssh_free(sesh);
}

sshConnect::sshConnect() : wxDialog(NULL, wxID_ANY, "SSH Login") {
    int width, height;
    GetSize(&width, &height);

    verticalContentSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *userHostBox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *passBox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *buttonBox = new wxBoxSizer(wxHORIZONTAL);

    userHostInput = new wxTextCtrl(this, -1, "");
    passwordInput = new wxTextCtrl(this, -1, "");

    userHostBox->Add(new wxStaticText(this, -1, "user@host"));
    userHostBox->Add(userHostInput);
    passBox->Add(new wxStaticText(this, -1, "pass"));
    passBox->Add(passwordInput);

    wxSize defaultButtonSize = wxButton::GetDefaultSize();
    submitButton = new wxButton(this, 70, "Submit");
    cancelButton = new wxButton(this, 71, "Cancel");
    buttonBox->Add(submitButton, 0, wxALIGN_CENTER_VERTICAL);
    buttonBox->AddSpacer(10);
    buttonBox->Add(cancelButton, 0, wxALIGN_CENTER_VERTICAL);

    verticalContentSizer->Add(userHostBox, 0, wxALIGN_CENTER);
    verticalContentSizer->Add(passBox, 0, wxALIGN_CENTER);
    verticalContentSizer->Add(buttonBox, 0, wxALIGN_CENTER);

    SetSizer(verticalContentSizer);
}

sshConnect::~sshConnect() {
    delete userHostInput;
    delete passwordInput; 
}

wxString sshConnect::getUserHost() {
    return userHostInput->GetLineText(0);
}

wxString sshConnect::getPass() {
    return passwordInput->GetLineText(0);
}




