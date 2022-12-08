#pragma once
#include <vector>
#include "Predmet.h"

enum Godina{prva=1, druga, treca, cetvrta, peta};

class Student {
private:
	char ime[20], prezime[20];
	int brIndeksa;
	vector<Predmet>predmeti;
	Godina godina;
public:
	Student();
	Student(const char* i, const char* p, int b, Godina g);
	void setIme();
	void setPrezime();
	vodi setBrIndeksa();
	void setGodina();
	char* getIme();
	char* getPrezime();
	int getBrIndeksa();
	Godina getGodina();
	friend istream& operator>>(istream& stream, Student& s);
	friend ostream& operator<<(ostream& stream, Student& s);
	void operator++();
	void operator++(int);
	friend float operator!(Studnet& s);
	void operator^(int n);
	static string getGodinaString(Godina x) {
		switch (x) {
		case prva:
			return "Prva.\n";
		case druga:
			return "Druga.\n";
		case treca:
			return "Treca.\n";
		case cetvrta:
			return "Cetvrta.\n";
		case peta:
			return "Peta.\n";
		default:
			return "Diplomirao!\n";
		}
	}
	~Student() = default;
};