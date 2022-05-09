#include "ArtistController.h"

ArtistController::ArtistController(ArtistRepository& repository) {
	this->m_repository = repository;
}

void ArtistController::addArtist(Artist* artist) {
	this->m_repository.addArtist(artist);
	m_undoStack.push(std::make_pair(ActionType::ADD, artist));
	//this->m_repository.iterateAndSave("musical_instruments_inventory.csv");
}

void ArtistController::displayAll() {
	m_repository.display(cout, [](Artist* i)->bool {
		cout << endl;
		return true; });
}

void ArtistController::removeByID(int id) {
	Artist* i = m_repository.removeArtist(id);
	if (i) {
		m_undoStack.push(std::make_pair(ActionType::REMOVE, i));
	}
	//this->m_repository.iterateAndSave("musical_instruments_inventory.csv");
}

int ArtistController::size() {
	return this->m_repository.size();
}

void ArtistController::displayByStreamsLowerThan(float streams) {
	this->m_repository.displayByStreamsLowerThan(streams);
}

void ArtistController::displayByType(string type) {
	this->m_repository.displayByType(type);
}

void ArtistController::undo() {
	if (this->m_undoStack.top().first == ActionType::ADD) {
		this->m_redoStack.push(std::make_pair(ActionType::ADD, this->m_undoStack.top().second));
		this->m_undoStack.pop();
		this->m_repository.removeArtist(this->m_redoStack.top().second->getID());
	}
	if (this->m_undoStack.top().first == ActionType::REMOVE) {
		this->m_redoStack.push(std::make_pair(ActionType::REMOVE, this->m_undoStack.top().second));
		this->m_undoStack.pop();
		this->m_repository.addArtist(this->m_redoStack.top().second);
	}
	//this->m_repository.iterateAndSave("musical_instruments_inventory.csv");
}

void ArtistController::redo() {
	if (this->m_redoStack.top().first == ActionType::ADD) {
		this->m_undoStack.push(std::make_pair(ActionType::ADD, this->m_redoStack.top().second));
		this->m_redoStack.pop();
		this->m_repository.addArtist(this->m_undoStack.top().second);
	}
	if (this->m_redoStack.top().first == ActionType::REMOVE) {
		this->m_undoStack.push(std::make_pair(ActionType::REMOVE, this->m_redoStack.top().second));
		this->m_redoStack.pop();
		this->m_repository.removeArtist(this->m_undoStack.top().second->getID());
	}
	//this->m_repository.iterateAndSave("musical_instruments_inventory.csv");
}

void ArtistController::read() {
	this->m_repository.readData("musical_instruments_inventory.csv");
}

void ArtistController::save() {
	this->m_repository.iterateAndSave("musical_instruments_inventory.csv");
}
