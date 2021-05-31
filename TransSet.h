#pragma once
#include "Trans.h"
#include <vector>

class TransSet {
private:
	int n;
	std::vector<Trans> trans;

public:
	Trans randomTranslation() {
		int r = rand() % n;
		return trans[r];
	}

	TransSet(int n_trans, std::vector<Trans> translations) : n(n_trans), trans(translations) {};
};