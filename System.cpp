#include "System.h"

System::System(wxWindow* parent) : wxWindow(parent, wxID_ANY) {
    wxStaticText* a = new wxStaticText(this, -1, "System");
}

System::~System() {

}
