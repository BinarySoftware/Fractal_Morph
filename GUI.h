#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/filedlg.h>
#include <wx/textfile.h>
#include <iostream>
#include "Instruction.h"
#include <wx/dcbuffer.h>
#include <wx/dcclient.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
	private:
		Instruction inst;
		std::vector<Points> end_frame_points;
		int current_fractal;

	protected:
		wxButton* m_button3;
		wxButton* m_button4;
		wxButton* m_button5;
		wxStaticText* m_staticText2;
		wxPanel* m_panel2;

		enum {
			ID_WXBUTTON_FILE =	1001,
			ID_WXBUTTON_MORPH =	1002,
			ID_WXBUTTON_NEXT = 1003
		};

	public:

		MyFrame( wxWindow* parent,
			wxWindowID id = wxID_ANY,
			const wxString& title = wxEmptyString,
			const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxSize( 562,348 ),
			long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL);

		~MyFrame();

		void draw();
		void windowOnResize(wxSizeEvent& e);
		void writeButtonOnClick(wxCommandEvent& e);
		void morphButtonOnClick(wxCommandEvent& e);
		void nextButtonOnClick(wxCommandEvent& e);
		Instruction deserialize(wxString& str, wxTextFile& tfile);
};

