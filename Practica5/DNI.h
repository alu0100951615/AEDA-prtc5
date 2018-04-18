#pragma once
#include <string>
#include <iostream>

using namespace std;

class DNI {

private:

	string letra;
	string key;
	string nombre_;
	string apellidos_;
	
public:
	static int comparaciones_;

	DNI(string nombre, string apellidos, string dni);

	DNI();

	~DNI();

	DNI(string dni);

	string get_key()const;

	string get_nom();

	string get_ape();

	operator int() const;

	friend std::ostream& operator<<(std::ostream& os, DNI& M);

	ostream& write(ostream& os)const;

	int operator<(const DNI& M);

	int operator>(const DNI& M);

	int operator<=(const DNI& M);

	bool operator==( DNI &d);
};

