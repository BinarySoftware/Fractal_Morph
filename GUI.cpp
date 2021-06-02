///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"
#include "Instruction.h"
#include <vector>
#include <string>
#include <sstream>

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	inst = Instruction();
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

	Bind(wxEVT_BUTTON, &MyFrame::morphButtonOnClick, this, ID_WXBUTTON_MORPH);

	m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("Gotowy."), wxDefaultPosition, wxDefaultSize, 0);
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

void MyFrame::morphButtonOnClick(wxCommandEvent& e) {
	m_staticText2->SetLabelText("Morfuje ...");
	wxClientDC clientDc(m_panel2);
	wxBufferedDC buffer(&clientDc);
	buffer.Clear();
	buffer.SetBackground(*wxBLACK_BRUSH);
	buffer.SetPen(*wxGREEN_PEN);

	for (Point point : end_frame_points[1]) {
		buffer.DrawPoint(wxPoint(inst.x_size / 2 - point.x(), inst.y_size / 2 - point.y()));
	}
	m_staticText2->SetLabelText("Gotowy");
}

void MyFrame::writeButtonOnClick(wxCommandEvent& e) {
	m_staticText2->SetLabelText("Wczytuje ...");
	wxString file;
	wxFileDialog fdlog(this, "Choose a file", "", "", "TXT files (*.txt)|*.txt");

	if (fdlog.ShowModal() != wxID_OK) return;
	file.Clear();
	file = fdlog.GetPath();

	wxString str;

	wxTextFile tfile;
	tfile.Open(file);

	inst = deserialize(str, tfile);
	for (int i = 0; i < inst.no_fract; i++) {
		end_frame_points.push_back(inst.calculate_fractal(i));
	}

	tfile.Close();

	wxClientDC clientDc(m_panel2);
	wxBufferedDC buffer(&clientDc);
	buffer.Clear();
	buffer.SetBackground(*wxBLACK_BRUSH);
	buffer.SetPen(*wxGREEN_PEN);

	for (Point point : end_frame_points[0]) {
		buffer.DrawPoint(wxPoint(inst.x_size/2 - point.x(), inst.y_size/2 - point.y()));
	}

	m_staticText2->SetLabelText("Gotowy");
}

Instruction MyFrame::deserialize(wxString& str, wxTextFile& tfile)
{

	/////// Rozmiar pola, liczba pikseli ///////
	str = tfile.GetFirstLine();
	std::stringstream test(str.ToStdString());
	std::string segment;
	std::vector<int> x_y_p;

	while (std::getline(test, segment, ',')) {
		x_y_p.push_back(atoi(segment.c_str()));
	}
	str = tfile.GetNextLine(); // Polozenie obserwatora wiec pomijamy dla 2d

	/////// Ilosc Fraktali ///////
	str = tfile.GetNextLine();
	int ilosc = wxAtoi(str);
	std::vector<TransSet> vts;
	std::vector<int> v_frames;

	for (int i = 0; i < ilosc; i++) {
		//Ile przeksztalcen dla pierwszego fraktala
		str = tfile.GetNextLine();
		int iter = wxAtoi(str);
		std::vector<Trans> vt;

		for (int j = 0; j < iter; j++) {
			//Przeksztalcenia dla pierwszego fraktala
			str = tfile.GetNextLine();
			std::stringstream test(str.ToStdString());
			std::string segment;
			std::vector<float> l;

			while (std::getline(test, segment, ' ')) {
				l.push_back(atof(segment.c_str()));
			}
			Trans t = Trans(l[0],l[1],l[2],l[3],l[4],l[5]);
			vt.push_back(t);
		}

		TransSet ts = TransSet(iter, vt);
		vts.push_back(ts);

		if (i != ilosc - 1) {
			//Ile klatek pomiedzy
			str = tfile.GetNextLine();
			int frames = wxAtoi(str);
			v_frames.push_back(frames);
		}
	}

	Instruction i = Instruction(x_y_p[0], x_y_p[1], x_y_p[2], ilosc, vts, v_frames);
	return i;
}
