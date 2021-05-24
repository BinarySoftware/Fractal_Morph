#pragma once
#include "TransSet.h"

class Instruction {
private:
	int x_size, y_size, no_iter;
	bool is2d;
	int no_fract;
	std::vector<TransSet> fractals;
	std::vector<int> frames_morph;

public:
	Instruction(int x, int y, int n, int n_f, std::vector<TransSet> ts, std::vector<int> f_m) :
		x_size(x), y_size(y), no_iter(n), is2d(true), no_fract(n_f), fractals(ts), frames_morph(f_m) {};
};