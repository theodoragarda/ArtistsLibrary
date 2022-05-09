#include "Artist.h"

Artist::Artist() {
	this->m_id = 0;
	this->m_streams = 0.0f;
}

Artist::Artist(int id, float streams) {
	this->m_id = id;
	this->m_streams = streams;
}

int Artist::getID() const {
	return this->m_id;
}

void Artist::setID(int newID) {
	try {
		if (isalpha(newID)) {
			throw exception();
		}
		else {
			this->m_id = newID;
		}

	}
	catch (int) {
		cout << "The ID introduced is not valid! Please try again!";
	}
}

float Artist::getStreams() const {
	return this->m_streams;
}

void Artist::setStreams(float newStreams) {
	this->m_streams = newStreams;
}

void Artist::display(ostream& os) const {
	os << setw(30);
	os << std::left << "ID: " << m_id << endl;
	os << setw(30);
	os << std::left << "Streams: " << m_streams << endl;
}


ostream& operator<<(ostream& os, const Artist& instrument)
{
	instrument.display(os);
	return os;
}
