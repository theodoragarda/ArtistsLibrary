#include "Artist.h"
#include "KHH.h"
#include "KRnB.h"
#include "ArtistRepository.h"
#include "ArtistController.h"
#include "UserInterface.h"
#include<iostream>
using namespace std;


int main() {
	cout << "Testing Artist:" << endl;
	cout << endl;
	Artist generic{4269, 30.6f};

	cout << "Generic: " << endl;
	generic.display(cout);
	cout << endl;
	cout << "The old ID is: " << generic.getID();
	generic.setID(123);
	cout << endl;
	cout << "The new ID is:" << generic.getID() << endl;
	cout << "The old streams are: " << generic.getStreams() << endl;
	generic.setStreams(120);
	cout << "The new streams are: " << generic.getStreams() << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;


	cout << "Testing KHH:" << endl;
	cout << endl;
	KHH hh1{ 5556, 70, 4, "AMBITION MUSIK", "ASH ISLAND" };

	hh1.display(cout);
	cout << endl;
	cout << "The old company is: " << hh1.getCompany() << endl;
	hh1.setCompany("MKIT RAIN RECORDS");
	cout << "The new company is: " << hh1.getCompany() << endl;
	cout << "The old number of albums is: " << hh1.getNrAlbums() << endl;
	hh1.setNrAlbums(3);
	cout << "The new number of albums is: " << hh1.getNrAlbums() << endl;
	cout << "The old name is: " << hh1.getName() << endl;
	hh1.setName("BLOO");
	cout << "The new name is: " << hh1.getName() << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;

	cout << "Testing KRnB:" << endl;
	cout << endl;
	KRnB rnb1{ 3214, 60, 7, "Fell Ghood Music", "BIBI" };

	rnb1.display(cout);
	cout << endl;
	cout << "The old company is: " << rnb1.getCompany() << endl;
	rnb1.setCompany("AXIS");
	cout << "The new company is: " << rnb1.getCompany() << endl;
	cout << "The old number of albums is: " << hh1.getNrAlbums() << endl;
	hh1.setNrAlbums(8);
	cout << "The new number of albums is: " << hh1.getNrAlbums() << endl;
	cout << "The old name is: " << hh1.getName() << endl;
	hh1.setName("Katie");
	cout << "The new name is: " << hh1.getName() << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;

	cout << "Testing ArtistRepository:" << endl;
	cout << endl;
	ArtistRepository repo;
	repo.addArtist(&generic);
	repo.addArtist(&hh1);
	repo.addArtist(&rnb1);

	repo.iterateAndSave("instruments.csv");

	repo.display(cout, [](Artist* i)->bool {
		if (dynamic_cast<KHH*>(i)) {
			return true;
		}
		return false;
		});
	cout << endl;

	repo.removeArtist(1234);

	repo.displayByStreamsLowerThan(70);
	cout << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << endl;


	cout << "Testing ArtistController:" << endl;
	ArtistController controller(repo);
	controller.displayAll();
	cout << endl;

	controller.removeByID(1234);
	controller.displayAll();
	cout << endl;

	controller.addArtist(&generic);
	controller.displayAll();
	cout << endl;

	UserInterface ui{ controller };

	ui.showMenu();

	return 0;
}