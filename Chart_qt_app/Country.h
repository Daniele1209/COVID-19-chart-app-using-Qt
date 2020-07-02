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
	/*
	//setters
	void set_ra(int i) { RA = i; }
	void set_dec(int i) { DEC = i; }
	void set_name(string nm) { name = nm; }
	void set_constellation(string c) { constellation = c; }
	void set_diameter(int i) { diameter = i; }
	*/

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