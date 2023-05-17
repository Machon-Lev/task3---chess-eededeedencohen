#include "Location.h"

Location::Location(int x, int y) {
	this->x = x;
	this->y = y;
}

Location::~Location() {}

bool Location::operator==(const Location& other) const {
	return (this->x == other.x && this->y == other.y);
}

int Location::getX() const {
	return this->x;
}

int Location::getY() const {
	return this->y;
}

void Location::moveTo(Location newLocation) {
	this->x = newLocation.x;
	this->y = newLocation.y;
}

string Location::getLocationOfChessFormat() const {
	string locationOfChessFormat = "";
	locationOfChessFormat += (char)(this->x + 49); // 49 is the ASCII code of '1'
	locationOfChessFormat += (char)(this->y + 65); // 65 is the ASCII code of 'A'
	return locationOfChessFormat;
}
