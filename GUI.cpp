
#include "GUI.h"
#include "Instruction.h"
#include <vector>
#include <string>
#include <sstream>

const wxPen* pens[5] = { wxRED_PEN,
						 wxBLUE_PEN,
						 wxGREEN_PEN,
						 wxYELLOW_PEN,
						 wxCYAN_PEN };

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

	m_button5 = new wxButton(this, ID_WXBUTTON_NEXT, wxT("Nastepny"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer5->Add(m_button5, 0, wxALL, 5);

	Bind(wxEVT_BUTTON, &MyFrame::nextButtonOnClick, this, ID_WXBUTTON_NEXT);

	m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("Gotowy."), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText2->Wrap(-1);
	bSizer5->Add(m_staticText2, 0, wxALL, 5);

	Bind(wxEVT_SIZE, &MyFrame::windowOnResize, this);

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

void MyFrame::nextButtonOnClick(wxCommandEvent& e) {

	if (current_fractal < inst.no_fract - 1) {

		current_fractal++;
	}
	else {
		current_fractal = 0;
	}

	m_staticText2->SetLabelText("Rysuje ...");

	wxClientDC clientDc(m_panel2);
	wxBufferedDC buffer(&clientDc);
	buffer.SetBackground(*wxBLACK_BRUSH);
	buffer.SetPen(*wxGREEN_PEN);
	buffer.Clear();
	for (int p = 0; p < end_frame_points[current_fractal].size(); p++) {
		buffer.SetPen(*end_frame_points[current_fractal][p].pen());
		Point end = end_frame_points[current_fractal][p];
		wxPoint pt = wxPoint(inst.x_size / 2 - end.x(), inst.y_size / 2 - end.y());
		buffer.DrawPoint(pt);
	}
	wxSize panelSize = m_panel2->GetSize();
	buffer.SetLogicalScale(((float)inst.x_size) / ((float)panelSize.x * 1.95), ((float)inst.y_size) / ((float)panelSize.y * 1.95));
	m_staticText2->SetLabelText("Gotowy");
}

void MyFrame::morphButtonOnClick(wxCommandEvent& e) {
	if (current_fractal < inst.no_fract - 1) {
		draw();
	}
	else {
		current_fractal = 0;
		draw();
	}
}

void MyFrame::draw() {
	m_staticText2->SetLabelText("Morfuje ...");
	wxClientDC clientDc(m_panel2);

	for (int i = current_fractal + 1; i < inst.no_fract; i++) {
		if (i != 1)
			Sleep(1000);
		int steps = inst.frames_morph[i - 1];
		for (int frame = 0; frame <= steps; frame++) {
			wxBufferedDC buffer(&clientDc);
			buffer.SetBackground(*wxBLACK_BRUSH);
			buffer.SetPen(*wxGREEN_PEN);
			buffer.Clear();
			for (int p = 0; p < end_frame_points[i].size(); p++) {
				buffer.SetPen(*end_frame_points[i - 1][p].pen());
				Point beg = end_frame_points[i - 1][p];
				Point end = end_frame_points[i][p];
				float dx = end.x() - beg.x();
				float dy = end.y() - beg.y();
				float step = ((float)frame) / ((float)steps);
				float curr_dx = dx * step;
				float curr_dy = dy * step;
				wxPoint pt = wxPoint(inst.x_size / 2 - (beg.x() + curr_dx), inst.y_size / 2 - (beg.y() + curr_dy));
				buffer.DrawPoint(pt);
			}
			wxSize panelSize = m_panel2->GetSize();
			buffer.SetLogicalScale(((float)inst.x_size) / ((float)panelSize.x * 1.95), ((float)inst.y_size) / ((float)panelSize.y * 1.95));
		}

		wxBufferedDC buffer(&clientDc);
		buffer.SetBackground(*wxBLACK_BRUSH);
		buffer.SetPen(*wxGREEN_PEN);
		buffer.Clear();
		for (int p = 0; p < end_frame_points[i].size(); p++) {
			buffer.SetPen(*end_frame_points[i][p].pen());
			Point end = end_frame_points[i][p];
			wxPoint pt = wxPoint(inst.x_size / 2 - end.x(), inst.y_size / 2 - end.y());
			buffer.DrawPoint(pt);
		}
		wxSize panelSize = m_panel2->GetSize();
		buffer.SetLogicalScale(((float)inst.x_size) / ((float)panelSize.x * 1.95), ((float)inst.y_size) / ((float)panelSize.y * 1.95));
		current_fractal = i;
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

	current_fractal = 0;
	inst = deserialize(str, tfile);
	for (int i = 0; i < inst.no_fract; i++) {
		end_frame_points.push_back(inst.calculate_fractal(i));
	}

	tfile.Close();

	wxClientDC clientDc(m_panel2);
	wxBufferedDC buffer(&clientDc);
	buffer.Clear();
	buffer.SetBackground(*wxBLACK_BRUSH);

	for (Point point : end_frame_points[0]) {
		buffer.SetPen(*point.pen());
		buffer.DrawPoint(wxPoint(inst.x_size / 2 - point.x(), inst.y_size / 2 - point.y()));
	}
	wxSize panelSize = m_panel2->GetSize();
	buffer.SetLogicalScale(((float)inst.x_size) / ((float)panelSize.x * 1.95), ((float)inst.y_size) / ((float)panelSize.y * 1.95));

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
			Trans t = Trans(l[0], l[1], l[2], l[3], l[4], l[5], pens[j]);
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


void MyFrame::windowOnResize(wxSizeEvent& e) {

	this->Layout();
	if (inst.no_fract > 0) {

		wxClientDC clientDc(m_panel2);
		wxBufferedDC buffer(&clientDc);
		buffer.Clear();
		buffer.SetBackground(*wxBLACK_BRUSH);

		for (Point point : end_frame_points[current_fractal]) {
			buffer.SetPen(*point.pen());
			buffer.DrawPoint(wxPoint(inst.x_size / 2 - point.x(), inst.y_size / 2 - point.y()));
		}



		wxSize panelSize = m_panel2->GetSize();
		buffer.SetLogicalScale(((float)inst.x_size) / ((float)panelSize.x * 1.95), ((float)inst.y_size) / ((float)panelSize.y * 1.95));

		m_staticText2->SetLabelText("Gotowy");

	}
}