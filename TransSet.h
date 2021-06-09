#pragma once
#include "Trans.h"
#include <vector>

/// <summary>
/// Klasa przechowuj¹ca wszystkie transformacje wymagane do wygenerowania jednego fraktala.
/// </summary>
class TransSet {
private:
	int n;
	std::vector<Trans> trans;

public:
	/// <summary>
	/// Zwraca losow¹ translacje.
	/// </summary>
	Trans randomTranslation() {
		int r = rand() % n;
		return trans[r];
	}

	/// <summary>
	/// Konstruktor g³ówny
	/// </summary>
	/// <param name="n_trans">Iloœæ transformacji</param>
	/// <param name="translations">Zbior transformacji</param>
	TransSet(int n_trans, std::vector<Trans> translations) : n(n_trans), trans(translations) {};
};