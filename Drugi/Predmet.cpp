#include <iostream>
using namespace std;
#include "Predmet.h"

Predmet::Predmet() {

}
Predmet::Predmet(const char* n, int o) {
	strcpy(this->naziv, n);
	this->ocjena = 0;
}
Predmet:Predmet(const Predmet& p) {
strcpy(this->naziv, p.naziv());
this->ocjena = p.ocjena;

}
void Predmet::setNaziv() {
	cout << "Unesite naziv: ";
	cin.getline(this->naziv, 50);
}
void Predmet::setOcjena() {
	cout << "Unesite ocjenu: ";
	cin >> this->ocjena;
	cin.ignore();
}
char* Predmet::getNaziv() {
	return this->naziv;
}
int Predmet::getOcjena() {
	return this->ocjena;
}
freind istream& operator>>(istream& stream, Predmet& p) {
	p.setNaziv();
	p.setOcjena();
	return stream;
}
friend ostream& operator<<(ostream& stream, Predmet& p) {
	stream << p.getNaziv() << " - (" << p.getOcjena() << ") \n";
	return stream;
}