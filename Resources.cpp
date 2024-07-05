#include "Resources.h"

Resources::Resources(wxWindow* parent) : wxWindow(parent, wxID_ANY) {
    wxStaticText* a = new wxStaticText(this, -1, "Resources");
}

Resources::~Resources() {

}
