#include "pch.h"
#include "CppUnitTest.h"
#include "../ArtistsLibrary/Artist.h"
#include "../ArtistsLibrary/Artist.cpp"

#include "../ArtistsLibrary/KHH.h"
#include "../ArtistsLibrary/KHH.cpp"

#include "../ArtistsLibrary/KRnB.h"
#include "../ArtistsLibrary/KRnB.cpp"

#include "../ArtistsLibrary/ArtistRepository.h"
#include "../ArtistsLibrary/ArtistRepository.cpp"

#include "../ArtistsLibrary/ArtistController.h"
#include "../ArtistsLibrary/ArtistController.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArtistLibraryInventoryTest
{
	TEST_CLASS(ArtistLibraryInventoryTest)
	{
	public:

		TEST_METHOD(TestClassArtist)
		{
			Artist generic{1234, 50.6f};

			Assert::AreEqual(generic.getID(), 1234);
			generic.setID(123);
			Assert::AreEqual(generic.getID(), 123);

			Assert::AreEqual(generic.getStreams(), 50.6f);
			generic.setStreams(120.0);
			Assert::AreEqual(generic.getStreams(), 120.0f);
		}

		TEST_METHOD(TestKHH) {
			KHH hh1{ 5556, 70, 4, "AMBITION MUSIK", "ASH ISLAND" };

			Assert::AreEqual(hh1.getCompany(), string("AMBITION MUSIK"));
			hh1.setCompany("MKIT RAIN RECORDS");
			Assert::AreEqual(hh1.getCompany(), string("MKIT RAIN RECORDS"));

			Assert::AreEqual(hh1.getNrAlbums(), 4);
			hh1.setNrAlbums(3);
			Assert::AreEqual(hh1.getNrAlbums(), 3);

			Assert::AreEqual(hh1.getType(), string("ASH ISLAND"));
			hh1.setType("BLOO");
			Assert::AreEqual(hh1.getType(), string("BLOO"));
		};

		TEST_METHOD(TestKRnB) {
			KRnB rnb1{ 3214, 60, 7, "Fell Ghood Music", "BIBI" };

			Assert::AreEqual(rnb1.getCompany(), string("Fell Ghood Music"));
			rnb1.setCompany("AXIS");
			Assert::AreEqual(rnb1.getCompany(), string("AXIS"));

			Assert::AreEqual(rnb1.getNrAlbums(), 7);
			rnb1.setNrAlbums(8);
			Assert::AreEqual(rnb1.getNrAlbums(), 8);

			Assert::AreEqual(rnb1.getType(), string("BIBI"));
			rnb1.setType("Katie");
			Assert::AreEqual(rnb1.getType(), string("Katie"));

			/*Assert::AreEqual(wi1.getMeansSound(), REED);
			wi1.setMeansSound(FLUTE);
			Assert::AreEqual(wi1.getMeansSound(), FLUTE);*/
		}

		TEST_METHOD(TestArtistRepository) {
			Artist generic{1234, 50.6f};
			KHH hh1{ 5556, 70, 4, "AMBITION MUSIK", "ASH ISLAND" };
			KRnB rnb1{ 3214, 60, 7, "Fell Ghood Music", "BIBI" };
			ArtistRepository repo;

			repo.addArtist(&generic);
			repo.addArtist(&hh1);
			repo.addArtist(&rnb1);

			Assert::AreEqual(repo.size(), 3);

			repo.removeArtist(1234);
			Assert::AreEqual(repo.size(), 2);

			cout << endl;
		}

		TEST_METHOD(TestArtistController) {
			Artist generic{1234, 50.6f};
			KHH hh1{ 5556, 70, 4, "AMBITION MUSIK", "ASH ISLAND" };
			KRnB rnb1{ 3214, 60, 7, "Fell Ghood Music", "BIBI" };
			ArtistRepository repo;

			repo.addArtist(&generic);
			repo.addArtist(&hh1);
			repo.addArtist(&rnb1);

			ArtistController controller(repo);

			controller.removeByID(1234);
			Assert::AreEqual(controller.size(), 2);

			controller.undo();
			Assert::AreEqual(controller.size(), 3);

			controller.redo();
			Assert::AreEqual(controller.size(), 2);

			controller.addArtist(&generic);
			Assert::AreEqual(controller.size(), 3);
		}
	};
}
