#include "KHH.h"

KHH::KHH() {
	this->m_nrAlbums = 0;
	this->m_name = ' ';
	this->m_company = ' ';
}

KHH::KHH(int id, float streams, int nrAlbums, string company, string name) : Artist(id, streams) {
	this->m_nrAlbums = nrAlbums;
	this->m_company = company;
	this->m_name = name;
}

int KHH::getNrAlbums() const {
	return this->m_nrAlbums;
}

void KHH::setNrAlbums(int newNrAlbums) {
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

string KHH::getCompany() const {
	return this->m_company;
}

void KHH::setCompany(string newCompany) {
	this->m_company = newCompany;
}

string KHH::getName() const {
	return this->m_name;
}

void KHH::setName(string newName) {
	this->m_name = newName;
}

void KHH::display(ostream& os) const {
	Artist::display(os);
	os << setw(30);
	os << "Nr. albums: " << m_nrAlbums << endl;
	os << setw(30);
	os << "Name: " << m_name << endl;
	os << setw(30);
	os << "Company: " << m_company << endl;
}

ostream& operator<<(ostream& os, const KHH& hartist) {
	hartist.display(os);
	return os;
}
