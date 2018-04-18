#include "DNI.h"

DNI::DNI(string nombre, string apellidos, string dni) {
	key.resize(9);
	key = dni;
	nombre_ = nombre;
	apellidos_ = apellidos;
}

DNI::DNI() {
	key.resize(9);
	for (int i = 0; i < 8; i++) {
		key[i] = '0' + rand() % 10;
	}
	key[8] = 'A' + rand() % 24;
}

DNI::~DNI() {
	key.resize(0);
}

DNI::DNI(string dni) {
	key = dni;
}

string DNI::get_key() const{
	return key;
}

string DNI::get_nom() {
	return nombre_;
}

string DNI::get_ape() {
	return apellidos_;
}

DNI::operator int() const {
	int a = (atoi(key.c_str()));

	return a;
}

bool DNI::operator==( DNI &d) {
	if (d.get_key() == key)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, DNI& M) {
	os << M.get_key();
	return os;
}

ostream & DNI::write(ostream & os)const
{

	os << get_key() << " " << letra << " ";
	return os;
}

int DNI::operator<(const DNI& M){

	comparaciones_++;
	//cout << comparaciones_ << " ";
	unsigned long a = *this;
	unsigned long b = M;

	if (a < b) return 1;
	else return 0;
}

int DNI::operator>(const DNI& M) {

	comparaciones_++;
	//cout << comparaciones_ << " ";
	unsigned long a = *this;
	unsigned long b = M;

	if (a > b) return 1;
	else return 0;
}

int DNI::operator<=(const DNI & M)
{
	comparaciones_++;
	
	unsigned long a = *this;
	unsigned long b = M;

	if (a <= b) return 1;
	else return 0;
}
