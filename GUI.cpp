///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer(wxVERTICAL);

	m_button3 = new wxButton(this, ID_WXBUTTON_FILE, wxT("Wczytaj"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer5->Add(m_button3, 0, wxALL, 5);

	Bind(wxEVT_BUTTON, &MyFrame::writeButtonOnClick, this, ID_WXBUTTON_FILE);

	m_button4 = new wxButton(this, ID_WXBUTTON_MORPH, wxT("Morfuj"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer5->Add(m_button4, 0, wxALL, 5);

	//Bind(wxEVT_BUTTON, &MyFrame::morphButtonOnClick, this, ID_WXBUTTON_MORPH);

	m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("..."), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText2->Wrap(-1);
	bSizer5->Add(m_staticText2, 0, wxALL, 5);


	bSizer4->Add(bSizer5, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(wxVERTICAL);

	m_panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	m_panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));

	bSizer6->Add(m_panel2, 1, wxEXPAND | wxALL, 5);


	bSizer4->Add(bSizer6, 1, wxEXPAND, 5);


	this->SetSizer(bSizer4);
	this->Layout();

	this->Centre(wxBOTH);
}

MyFrame::~MyFrame()
{
}

void MyFrame::writeButtonOnClick(wxCommandEvent& e) {
	wxString file;
	wxFileDialog fdlog(this, "Choose a file", "", "", "TXT files (*.txt)|*.txt");

	if (fdlog.ShowModal() != wxID_OK) return;
	file.Clear();
	file = fdlog.GetPath();

	wxString str;

	wxTextFile tfile;
	tfile.Open(file);

	str = tfile.GetFirstLine();

	//Rozmiar pola

	str = tfile.GetNextLine(); // Polozenie obserwatora wiec pomijamy dla 2d

	str = tfile.GetNextLine();

	//Ile fraktali

	str = tfile.GetNextLine();

	//Ile przeksztalcen dla pierwszego fraktala

	int it1 = wxAtoi(str);

	while (it1 > 0) {
		str = tfile.GetNextLine();

		//Przeksztalcenia dla pierwszego fraktala
		it1--;
	}

	str = tfile.GetNextLine();

	//Ile klatek pomiedzy

	str = tfile.GetNextLine();

	//Ile przeksztalcen dla drugiego fraktala

	while (!tfile.Eof()) {
		str = tfile.GetNextLine();

		//Przeksztalcenia dla drugiego fraktala
	}
}
