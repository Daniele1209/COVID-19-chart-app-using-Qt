#pragma once
#include "Country.h"
#include <fstream>
#include <iostream>

using namespace std;

class Repo {
private:
	string csv_path;
	vector<Country> countries;

public:
	Repo(const string& a = "") : csv_path(a) {
		if (csv_path.size()) load_file();

	}
	void load_file();
	vector<Country> get_countries();
	~Repo() {}
};