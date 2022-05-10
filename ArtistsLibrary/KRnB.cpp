#include "KRnB.h"

KRnB::KRnB() {
	this->m_nrAlbums = 0;
	this->m_name = ' ';
	this->m_company = ' ';
}

KRnB::KRnB(int id, float streams, int nrAlbums, string company, string name) : Artist(id, streams) {
	this->m_nrAlbums = nrAlbums;
	this->m_company = company;
	this->m_name = name;
}

int KRnB::getNrAlbums() const {
	return this->m_nrAlbums;
}

void KRnB::setNrAlbums(int newNrAlbums) {
	try {
		if (isalpha(newNrAlbums)) {
			throw exception();
		}
		else {
			this->m_nrAlbums = newNrAlbums;
		}
	}
	catch (int) {
		cout << "The number of albums is invalid! Please try again!";
	}
}

string KRnB::getCompany() const {
	return this->m_company;
}

void KRnB::setCompany(string newCompany) {
	this->m_company = newCompany;
}

string KRnB::getName() const {
	return this->m_name;
}

void KRnB::setName(string newName) {
	this->m_name = newName;
}

void KRnB::display(ostream& os) const {
	Artist::display(os);
	os << setw(30);
	os << "Nr. albums: " << m_nrAlbums << endl;
	os << setw(30);
	os << "Name: " << m_name << endl;
	os << setw(30);
	os << "Company: " << m_company << endl;
}

ostream& operator<<(ostream& os, const KRnB& rartist) {
	rartist.display(os);
	return os;
}
