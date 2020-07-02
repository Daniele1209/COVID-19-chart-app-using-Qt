#include "Repository.h"

void Repo::load_file() {
    ifstream f(this->csv_path);
    Country curr;
    while (f >> curr)
    {
        this->countries.push_back(curr);
    }
    f.close();
}

vector<Country> Repo::get_countries() {
    return this->countries;
}
