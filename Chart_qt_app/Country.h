#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Country {
private:
	string date;
	string name;
	int new_cases;
	int new_deaths;
	int total_cases;
	int total_deaths;


public:
	Country();
	Country(string& d, string& n, int nc, int nd, int tc, int td);
	//getters
	int get_newc() { return this->new_cases; }
	int get_newd() { return this->new_deaths; }
	int get_totalc() { return this->total_cases; }
	int get_totald() { return this->total_deaths; }
	string get_name() { return this->name; }
	string get_date() { return this->date; }
	
	//setters
	void set_date(string d) { date = d; }
	void set_name(string n) { name = n; }
	void set_newc(int nc) { new_cases = nc; }
	void set_newd(int nd) { new_deaths =nd; }
	void set_totalc(int tc) { total_cases = tc; }
	void set_totald(int td) { total_deaths = td; }
	

	//string mode
	//string to_String();

	//tokenize
	vector<string> tokenize(string& str, char separator);

	//operators
	friend bool operator==(Country&, Country&);
	friend istream& operator>>(istream& is, Country& p);
	friend ostream& operator<<(ostream& os, Country& p);

	~Country() {}
};