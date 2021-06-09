#pragma once
#include "Trans.h"
#include <vector>

/// <summary>
/// Klasa przechowuj�ca wszystkie transformacje wymagane do wygenerowania jednego fraktala.
/// </summary>
class TransSet {
private:
	int n;
	std::vector<Trans> trans;

public:
	/// <summary>
	/// Zwraca losow� translacje.
	/// </summary>
	Trans randomTranslation() {
		int r = rand() % n;
		return trans[r];
	}

	/// <summary>
	/// Konstruktor g��wny
	/// </summary>
	/// <param name="n_trans">Ilo�� transformacji</param>
	/// <param name="translations">Zbior transformacji</param>
	TransSet(int n_trans, std::vector<Trans> translations) : n(n_trans), trans(translations) {};
};