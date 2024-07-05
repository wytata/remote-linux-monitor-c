// Start of wxWidgets "Hello World" Program #include <wx/wx.h>
#define LIBSSH_STATIC 1
#include <libssh/libsshpp.hpp>
#include "sshConnect.h"
#include <wx-3.2/wx/notebook.h>
#include "FileSystem.h"
#include "System.h"
#include "Resources.h"
#include "Processes.h"
 
class MyApp : public wxApp
{
public: bool OnInit() override;
};

 
wxIMPLEMENT_APP(MyApp);
 
class MyFrame : public wxFrame
{
public:
    MyFrame();
 
private:
    void OnConnect(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

MyFrame *frame;
 
enum
{
    ID_Connect = 1,
    ID_Disconnect = 2,
    ID_SSHOptions = 3,
};
 
bool MyApp::OnInit()
{
    frame = new MyFrame();
    frame->Show(true);
    return true;
}
 
MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Hello World")
{
    // monitor edit view help
    
    wxMenu *menuMonitor = new wxMenu;
    //connect disconnect sshoptions quit
    menuMonitor->Append(ID_Connect, "&Connect");
    menuMonitor->AppendSeparator();
    menuMonitor->Append(ID_Disconnect, "&Disconnect");
    menuMonitor->AppendSeparator();
    menuMonitor->Append(ID_Connect, "&SSH Options");
    menuMonitor->AppendSeparator();
    menuMonitor->Append(wxID_EXIT);
 
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenu *menuEdit = new wxMenu;
    wxMenu *menuView = new wxMenu;
 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuMonitor, "&Monitor");
    menuBar->Append(menuEdit, "&Edit");
    menuBar->Append(menuView, "&View");
    menuBar->Append(menuHelp, "&Help");
 
    SetMenuBar( menuBar );
 
    //CreateStatusBar();
    //SetStatusText("Welcome to wxWidgets!");
 
    Bind(wxEVT_MENU, &MyFrame::OnConnect, this, ID_Connect);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

    wxNotebook *nb = new wxNotebook(this, -1, wxDefaultPosition, wxDefaultSize, wxNB_TOP, "notebookname");
    nb->AddPage(new System(nb), "System");
    nb->AddPage(new Processes(nb), "Processes");
    nb->AddPage(new Resources(nb), "Resources");
    nb->AddPage(new FileSystem(nb), "File Systems");
    printf("selected page is %d\n", nb->GetSelection());
}
 
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
 
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
 
void MyFrame::OnConnect(wxCommandEvent& event)
{
    sshConnect sshConnectDialog;
    sshConnectDialog.ShowModal();
}


