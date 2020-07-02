#include "Country.h"

Country::Country() : date(""), name(""), new_cases(), new_deaths(), total_cases(), total_deaths() {}

Country::Country(string& d, string& n, int nc, int nd, int tc, int td) {
    this->name = n;
    this->date = d;
    this->new_cases = nc;
    this->new_deaths = nd;
    this->total_cases = tc;
    this->total_deaths = td;
}

vector<string> Country::tokenize(string& str, char separator) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, separator))
        result.push_back(token);
    return result;
}

bool operator==(Country& p1, Country& p2) {
    return{
           p1.get_name() == p2.get_name() &&
           p1.get_date() == p2.get_date() &&
           p1.get_newc() == p2.get_newc() &&
           p1.get_newd() == p2.get_newd() &&
           p1.get_totalc() == p2.get_totalc() &&
           p1.get_totald() == p2.get_totald()
    };
}

ostream& operator<<(ostream& os, Country& p) {
    os << p.get_date() << "," << p.get_name() << "," << to_string(p.get_newc()) << "," << to_string(p.get_newd()) 
        << "," << to_string(p.get_totalc()) << "," << to_string(p.get_totald()) << endl;
    return os;
}