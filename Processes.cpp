#include "Processes.h"

Processes::Processes(wxWindow* parent) : wxWindow(parent, wxID_ANY) {
    wxStaticText* a = new wxStaticText(this, -1, "Processes");
}

Processes::~Processes() {

}
