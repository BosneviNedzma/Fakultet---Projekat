#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() {
	strcpy(this->ime, "Novi");
	strcpy(this->prezime, "Student");
	this->brIndeksa = 0;
	this->godina = prva;
}

Student::Student(const char* i, const char* p, int b, Godina g) {
	strcpy(this->ime, i);
	strcpy(this->prezime, p);
	this->brIndeksa = b;
	this->godina = g;
}

void Student::setIme() {
	cout << "Unesite ime: ";
	cin.getline(this->ime, 20);
}
void Student::setPrezime(){
	cout << "Unesite prezime: ";
	cin.getline(this->prezime, 20);
}
void Student::setBrIndeksa() {
	cout << "Unesite broj indeksa: ";
	cin >> this->brIndeksa;
}
void Student::setGodina() {
	shared_ptr<int>x = make_shared<int>();
	do{
		cout << "Unesite godinu studija: ";
		cin >> *x;
	} while (*x < 1 || *x>5);
	this->godina = static_cast<Godina>(*x);
	cin.ignore();
	this->godina = static_cast<Godina>(*x);
}

char* Student::getIme() {
	return this->ime;
}
char* Student::getPrezime() {
	return this->prezime;
}
int Student::getBrIndeksa() {
	return this->brIndeksa;
}
Godina Student::getGodina() {
	return this->godina;
}
 istream& operator>>(istream& stream, Student& s) {
	s.setIme();
	s.setPrezime();
	s.setBrIndeksa();
	s.setGodina();
	int x;
	do {
		cout << "\nUnesite 0 za kraj, bilo koji drugi broj za unos novog predmeta" << endl;
		cin >> x;
		cin.ignore();
		if (x != 0) s.setPredmet();
	} while (x != 0);
	return stream;
}
 ostream& operator<<(ostream& stream, Student& s) {
	system("cls");
	stream << "Student: " << s.getIme() << " " << s.getPrezime() << " - " << s.getBrIndeksa() << endl;
	stream << "Godina studija: " << Student::getGodinaString(s.getGodina());
	stream << "R. br. \tPredmet i ocjena\n";
	stream << "---------------------------------\n";
	for (int i = 0; i < s.getPredmeti().size(); i++) {
		stream << i + 1 << "\t" << s.getPredmeti()[i] << "\n";
	}
	return stream;
}
 void Student::operator++() {
	 int x = static_cast<int>(this->getGodina());
	 if (x < 5) {
		 x++;
		 this->godina = static_cast<Godina>(x);
	 }
}
 void Student::operator++(int) {
	 this->brIndeksa++;
}
 void Student::operator^(int n) {
	 this.getPredmeti().erase(this.getPredmeti().begin() + n - 1);
	 cout << "\nPredmet uspjesno obrisan";
}