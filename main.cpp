#include <wx/wxprec.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/dcbuffer.h>
#include <array>

class MyFrame : public wxFrame {
public:
	MyFrame(wxWindow* parent,
		wxWindowID id = wxID_ANY,
		const wxString& title = wxEmptyString,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxSize(600, 400),
		long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	~MyFrame();
};

MyFrame::MyFrame(wxWindow* parent,
	wxWindowID id,
	const wxString& title,
	const wxPoint& pos,
	const wxSize& size,
	long style) : wxFrame(parent, id, title, pos, size, style) {
	this->SetSizeHints(wxSize(-1, -1), wxDefaultSize);

}

MyFrame::~MyFrame() {

}

class MyApp : public wxApp {
public:
	virtual bool OnInit() {
		MyFrame* frame = new MyFrame(NULL, wxID_ANY, "Fraktale", wxDefaultPosition, wxSize(1116, 577));
		frame->Show(true);
		SetTopWindow(frame);
		return true;
	}
};

wxIMPLEMENT_APP(MyApp);