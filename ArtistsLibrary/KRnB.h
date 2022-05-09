#pragma once
#include "Artist.h"
#include<array>
#include<cctype>
#include<iostream>
#include<map>
using namespace std;

class KRnB : public Artist {
public:
	/**
	 * Default constructor.
	 *
	 * \return nothing
	 */
	KRnB();

	/**
	 * Constructor with parameters.
	 *
	 * \param id : the ID of the artist (inherited from the Artist class)
	 * \param streams : the streams of the artist (inherited from the Artist class)
	 * \param nrAlbums : the number of albums the artist has
	 * \param company : the company the artist is part of
	 * \param name : the name of the artist
	 * \return nothing
	 */
	KRnB(int id, float streams, int nrAlbums, string company, string name);

	/**
	 * Overloading the  << operator.
	 * \param os : the ostream parameter we use to store the output stream
	 * \param rartist : the artist
	 * \return the output stream
	 */
	friend ostream& operator<<(ostream& os, const KHH& rartist);

	/**
	 * Getter for the number of albums.
	 * \return the number of albums of the artist
	 */
	int getNrAlbums() const;

	/**
	 * Setter for the number of albums.
	 */
	void setNrAlbums(int newNrAlbums);

	/**
	 * Getter for the company.
	 *
	 * \return the company of the artist
	 */
	string getCompany() const;

	/**
	 * Setter for the company.
	 */
	void setCompany(string newCompany);

	/**
	 * Getter for name.
	 *
	 * \return the name of the artist
	 */
	string getName() const;

	/**
	 * Setter for name.
	 *
	 * \return the name of the artist
	 */
	void setName(string newName);

	/**
	 * Display method - override for the one in the Artist class.
	 * \param os : the ostream operator
	 */
	void display(ostream& os) const override;

	/**
	 * Override for the saveToCSV function from the base class Artist.
	 *
	 * \param outputFile : the name/path of the .csv file
	 */
	void saveToCSV(ostream& outputFile) override {
		Artist::saveToCSV(outputFile);
		outputFile << "," << m_nrAlbums << "," << m_company << "," << m_name;
	}

private:
	int m_nrAlbums;
	string m_company;
	string m_name;
};