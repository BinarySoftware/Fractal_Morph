#include <wx/wx.h>
#include "GUI.h"

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