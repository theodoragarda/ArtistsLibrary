#include "UserInterface.h"

UserInterface::UserInterface(ArtistController& controller) : m_controller{ controller }
{
}

void UserInterface::add() {
	int id;
	float streams;
	cout << "Enter the ID: "; cin >> id;
	cout << endl;
	cout << "Enter the streams: "; cin >> streams;
	cout << endl;

	cout << "Do you want to add a khh artist or a krnb artist?" << endl;
	cout << "\t y - Yes";
	cout << endl;
	cout << "\t n - No";
	cout << endl;

	char option1;
	char option2;

	cout << "Option: "; cin >> option1;
	cout << endl;

	if (option1 == 'y') {
		cout << "khh artist or krnb artist?" << endl;
		cout << "\t h - KHH" << endl;
		cout << "\t r - KRnB" << endl;

		cout << "Your option: "; cin >> option2;
		cout << endl;
		if (option2 == 'h') {
			string company;
			int nrAlbums;
			string name;
			cout << "Enter the company: "; cin >> company;
			cout << endl;
			cout << "Enter the number of albums: "; cin >> nrAlbums;
			cout << endl;
			cout << "Enter the name: "; cin >> name;
			cout << endl;

			KHH* hartist = new KHH{ id, streams, nrAlbums, company, name };
			m_controller.addArtist(hartist);
		}
		if (option2 == 'r') {
			string company;
			int nrAlbums;
			string name;
			cout << "Enter the company: "; cin >> company;
			cout << endl;
			cout << "Enter the number of albums: "; cin >> nrAlbums;
			cout << endl;
			cout << "Enter the name: "; cin >> name;
			cout << endl;

			KRnB* rartist = new KRnB{ id, streams, nrAlbums, company, name };
			m_controller.addArtist(rartist);
		}

	}
	else if (option1 == 'n') {
		Artist* artist = new Artist{ id, streams };
		m_controller.addArtist(artist);
	}
	else {
		cout << "Invalid option! Please try again!";
	}
}

void UserInterface::remove() {
	int id;
	cout << "Enter the ID of the artist you want to remove: "; cin >> id;
	m_controller.removeByID(id);
}

void UserInterface::showMenu() {
	char option;
	do {
		this->m_controller.read();
		cout << endl;
		cout << "Hello, welcome to our library! Please enter your option from the list below: " << endl;
		cout << "\t a - Add an artist" << endl;
		cout << "\t r - Remove an artist by ID" << endl;
		cout << "\t d - Display all artists" << endl;
		cout << "\t f - Filter artists" << endl;
		cout << "\t u - Undo" << endl;
		cout << "\t z - Redo" << endl;
		cout << "\t e - Exit" << endl;
		cin >> option;
		switch (option) {
		default:
			break;

		case'a':
			add();
			break;

		case'r':
			remove();
			break;

		case'd':
			m_controller.displayAll();
			break;

		case'f':
			int optionFilter;
			cout << "What particular artist do you want to see?" << endl;
			cout << "Here are your options: " << endl;
			cout << "\t 1 - Artists having streams lower than a given number" << endl;
			cout << "\t 2 - Artists of a given name" << endl;
			cout << "Your option: "; cin >> optionFilter;
			cout << endl;
			try {
				if (optionFilter == 1) {
					float streams;
					cout << "Enter the maximum streams number: "; cin >> streams;
					cout << endl;
					this->m_controller.displayByStreamsLowerThan(streams);
					break;
				}
				if (optionFilter == 2) {
					string type;
					cout << "Here are the types of artists we currently have in our library: " << endl;
					cout << "\t h - KHH" << endl;
					cout << "\t r - KRnB" << endl;
					cout << "Enter an option (h for KHH and r for KRnB): "; cin >> type;
					this->m_controller.displayByType(type);
					break;
				}
			}
			catch (std::invalid_argument &e) {
                std::cout<<e.what();
			}

		case'u':
			m_controller.undo();

		case'z':
			m_controller.redo();

		case'e':
			this->m_controller.save();
			cout << "Thank you for coming! See you again soon!" << endl;
			exit(0);
			break;
		}

	} while (true);
	cout << endl;
}

void UserInterface::displayByLowerStreams(float streams) {
	this->m_controller.displayByStreamsLowerThan(streams);
}

void UserInterface::displayByType(string type) {
	this->m_controller.displayByType(type);
}
