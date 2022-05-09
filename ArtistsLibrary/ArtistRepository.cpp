#include "ArtistRepository.h"

ArtistRepository::ArtistRepository() {
	this->readData("musical_instruments_inventory.csv");
}

Artist* ArtistRepository::operator[](int i) {
	return this->m_repo[i];
}

void ArtistRepository::addArtist(Artist* i) {
	m_repo.push_back(i);
}

Artist* ArtistRepository::removeArtist(int id) {
	Artist* artist = nullptr;
	auto index = find_if(m_repo.begin(), m_repo.end(), [id](Artist* artist)->bool {
		return artist->getID() == id;
		});
	if (index != m_repo.end()) {
		artist = *index;
		m_repo.erase(index);
	}
	return artist;
}

int ArtistRepository::size() {
	return this->m_repo.size();
}

ostream& ArtistRepository::display(ostream& os, bool(*function)(Artist* i)) {
	for (auto i = 0; i < m_repo.size(); i++) {
		if (function(m_repo[i])) {
			os << *m_repo[i];
		}
	}
	return os;
}

void ArtistRepository::displayByStreamsLowerThan(float streams) {
	int k = 0;
	for (size_t i = 0; i < m_repo.size(); i++) {
		if (m_repo[i]->getStreams() < streams) {
			m_repo[i]->display(cout);
			k++;
			cout << endl;
		}
	}
	if (k == 0) {
		cout << "There were no artists with the streams under " << streams << "!";
	}
}

void ArtistRepository::displayByType(string type) {
	vector<Artist*> validKHH;
	vector<Artist*> validKRnB;

	for (size_t i = 0; i < this->m_repo.size(); i++) {
		if (dynamic_cast<KHH*>(this->m_repo[i])) {
			validKHH.push_back(this->m_repo[i]);
		}
		if (dynamic_cast<KRnB*>(this->m_repo[i])) {
			validKRnB.push_back(this->m_repo[i]);
		}
	}

	if (type == "h") {
		for (auto i = 0; i < validKHH.size(); i++) {
			validKHH[i]->display(cout);
			cout << endl;
		}
	}
	else {
		if (type == "r") {
			for (auto i = 0; i < validKRnB.size(); i++) {
				validKRnB[i]->display(cout);
				cout << endl;
			}
		}
		else {
			cerr << "Invalid command!";
		}
	}
}

bool ArtistRepository::saveData(const char* csv_path, Artist* i) {
	ofstream outputFile;

	outputFile.open(csv_path, fstream::out);

	outputFile << i->getID() << "," << i->getStreams() << ",";
	if (dynamic_cast<KHH*>(i)) {
		outputFile << dynamic_cast<KHH*>(i)->getCompany() << "," << dynamic_cast<KHH*>(i)->getNrAlbums() << "," << dynamic_cast<KHH*>(i)->getType() << endl;
	}

	else {
		if (dynamic_cast<KRnB*>(i)) {
			outputFile << dynamic_cast<KRnB*>(i)->getCompany() << "," << dynamic_cast<KRnB*>(i)->getNrAlbums() << "," << dynamic_cast<KRnB*>(i)->getType() << endl;
		}
		outputFile.close();
		return true;
	}

	void ArtistRepository::iterateAndSave(const char* csv_path) {
		ifstream oldFile(csv_path);
		ofstream outputFile("new_musical_instruments_inventory.csv");

		for (auto i = 0; i < this->m_repo.size(); i++) {
			this->m_repo[i]->saveToCSV(outputFile);
			outputFile << endl;
		}
		if (!remove(csv_path) != 0) {
			perror("Failed to delete file! :c");
		}

		else {
			rename("new_musical_instruments_inventory.csv", csv_path);
		}
	}

	bool ArtistRepository::readData(const char* csv_path) {
		ifstream inputFile;
		string data;

		inputFile.open(csv_path, fstream::in);

		do {
			// reads data from the file until we reach the end of the file (EOF == true)
			inputFile >> data;

		} while (!EOF);

		inputFile.close();
		return true;
	}
