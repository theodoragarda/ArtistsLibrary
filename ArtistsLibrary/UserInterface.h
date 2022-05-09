#pragma once
#include "ArtistController.h"

class UserInterface {
public:
	/**
	 * Constructor.
	 *
	 * \param controller : the controller used to perform operations on the repository
	 * \return nothing
	 */
	UserInterface(ArtistController& controller);

	/**
	 * Add an artist.
	 *
	 */
	void add();

	/**
	 * Remove an artist.
	 *
	 */
	void remove();

	/**
	 * Display the menu.
	 *
	 */
	void showMenu();

	/**
	 * Displays the artist from the repo which has the streams lower than a given value.
	 *
	 * \param streams : the upper bound of the streams
	 */
	void displayByLowerStreams(float streams);

	/**
	 * Displays the artists from the repo which are of a given type.
	 *
	 * \param type : the type of the artists
	 * h - KHH
	 * r - KRnB
	 * throws an exception if type is neither "h" nor "r"
	 */
	void displayByType(string type);

private:
	ArtistController m_controller;
};

