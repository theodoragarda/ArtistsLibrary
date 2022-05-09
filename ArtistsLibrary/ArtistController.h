#pragma once
#include "ArtistRepository.h"
#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

enum class ActionType {
	ADD,
	REMOVE
};

class ArtistController {
public:
	/**
	 * Constructor.
	 *
	 * \param repository : the repository we store our objects in
	 * \return nothing
	 */
	ArtistController(ArtistRepository& repository);

	/**
	 * Add an artist to the repository.
	 *
	 * \param artist : the artist we want to add to the repository
	 */
	void addArtist(Artist* artist);

	/**
	 * Display the content of the repository.
	 *
	 */
	void displayAll();

	/**
	 * Remove an artist by ID.
	 *
	 * \param id : the ID of the artist we want to remove
	 */
	void removeByID(int id);

	/**
	 * Displays the artists having the streams lower than a given value
	 *
	 * \param streams : the upper bound of the streams
	 */

	 /**
	  * Computes the number of elements in the shop.
	  *
	  * \return the number of artists
	  */
	int size();

	/**
	 * Display the artists which have the streams lower than a specified value.
	 *
	 * \param streams : the upper bound of the value of the streams
	 */
	void displayByStreamsLowerThan(float streams);

	/**
	 * Display only objects of a certain type.
	 *
	 * \param type : the type of the artist
	 * h - KHH
	 * r - KRnB
	 * throws an exception if the type is neither "h" nor "r"
	 */
	void displayByType(string type);

	/**
	 * Undo the last action performed.
	 * if the last action was ADD, the artist added will be removed
	 * if the last action was REMOVE, the artist removed will be added back into the repository
	 *
	 */
	void undo();

	/**
	 * Redo the last action that was previously undone.
	 * if the action was REMOVE, the artist which was added after the undo() will be removed once again into the repository
	 * if the last action was ADD, the artist which was removed by the undo() will be added once again into the repository
	 *
	 */
	void redo();

	/**
	 * Read the data from the .csv file where the artists are stored.
	 *
	 */
	void read();

	/**
	 * Save the changes in the .csv file where the artists are stored.
	 *
	 */
	void save();

private:
	ArtistRepository m_repository;
	std::stack<pair<ActionType, Artist*>> m_undoStack;
	std::stack<pair<ActionType, Artist*>> m_redoStack;
};

