#pragma once
#include<string>
#include<ostream> 
#include<istream> 
#include<iomanip>
#include<iostream>
#include<cctype>
using namespace std;

class Artist {
public:
	/**
	 * Default constructor.
	 *
	 * \return nothing
	 */
	Artist();

	/**
	 * Constructor with parameters.
	 *
	 * \param id : the ID of the artist
	 * \param streams : the price of the artist
	 * \return nothing
	 */
	Artist(int id, float streams);

	/**
	 * Overloading the << operator.
	 *
	 * \param os : the ostream parameter we use to store the output stream
	 * \param artist : the artist
	 * \return the output stream
	 */
	friend ostream& operator<<(ostream& os, const Artist& artist);

	/**
	 * Getter for ID.
	 * \return the ID of the artist
	 */
	int getID() const;

	/**
	 * Setter for ID.
	 */
	void setID(int newID);

	/**
	 * Getter for streams.
	 * \return the streams of the artist
	 */
	float getStreams() const;

	/**
	 * Setter for streams.
	 */
	void setStreams(float newStreams);

	/**
	 * Display method.
	 *
	 * \param os : the ostream operator
	 */
	virtual void display(ostream& os) const;

	/**
	 * Saves the data into a .csv file.
	 *
	 * \param outputFile : the name/path of the .csv file
	 */
	virtual void saveToCSV(ostream& outputFile) {
		outputFile << m_id << "," << m_streams;
	}

private:
	/**
	 * the ID of an artist is unique.
	 */
	int m_id;
	float m_streams;
};

