#pragma once
#include "Artist.h"
#include "KHH.h"
#include "KRnB.h"
#include<ostream>
#include<vector>
#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

class ArtistRepository {
public:
	/**
	 * Default constructor.
	 * Reads data from the .csv file
	 *
	 */
	ArtistRepository();

	/**
	 * Overload for the indexing/subscript operator.
	 *
	 * \param i : the index of the element we want to get
	 * \return a reference to the i-th elementin the array
	 */
	Artist* operator[](int i);

	/**
	 * Add an artist to the repository.
	 *
	 * \param i : the artist we want to add to the repository
	 */
	void addArtist(Artist* i);

	/**
	 * Remove instrument by ID.
	 *
	 * \param id : the ID of the element we want to delete
	 * \return the artist we deleted
	 */
	Artist* removeArtist(int id);

	/**
	 * Computes the size of the repository.
	 *
	 * \return the number of artists in the repository
	 */
	int size();

	/**
	 * Display method - displays an artist based on a property.
	 *
	 * \param os : the ostream operator we will use to display the artist oject
	 * \param function : the property the artist shall fulfill in order to be eligible for display
	 * \return the artist in the way described in the function
	 */
	ostream& display(ostream& os, bool (*function)(Artist* i));

	/**
	 * Display all artists which have the streams lower than a given value.
	 *
	 * \param streams : the value we compare the streams to
	 */
	void displayByStreamsLowerThan(float streams);

	/**
	 * Displays all the artists of a certain type.
	 *
	 * \param type : the type of the artists
	 * h - KHH
	 * r - KRnB
	 * throws an exception if type is neither "h" nor "r"
	 */
	void displayByType(string type);

	/**
	 * Read data from a .csv file.
	 *
	 * \param csv_path : the path of the .csv file
	 * \return true if the data has been successfully read from the file
	 */
	static bool readData(const char* csv_path);

	/**
	 * Save all data from the repository in a .csv file.
	 *
	 */
	void iterateAndSave(const char* csv_path);

	/**
	 * Save the data in a .csv file.
	 *
	 * \param csv_path : the path of the .csv file
	 * \param i : the data itself
	 * \return true if the data has been successfully saved
	 */
	bool saveData(const char* csv_path, Artist* i);


private:
	vector<Artist*> m_repo;
};

