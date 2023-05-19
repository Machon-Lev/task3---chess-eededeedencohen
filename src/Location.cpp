#include <iostream>
#include "Location.h"


Location::Location() {
	this->x = -1;
	this->y = -1;
}

Location::Location(int x, int y) {
	this->x = x;
	this->y = y;
}

Location::~Location() {}

bool Location::operator==(const Location& other) const {
	return (this->x == other.x && this->y == other.y);
}

// << operator for printing the location
std::ostream& operator<<(std::ostream& os, const Location& location) {
	os << "(" << location.x << "," << location.y << ")";
	return os;
}


int Location::getX() const {
	return this->x;
}

int Location::getY() const {
	return this->y;
}

void Location::moveTo(Location newLocation) {
	this->x = newLocation.getX();
	this->y = newLocation.getY();
}

string Location::getLocationOfChessFormat() const {
	string locationOfChessFormat = "";
	locationOfChessFormat += (char)(this->x + 49); // 49 is the ASCII code of '1'
	locationOfChessFormat += (char)(this->y + 65); // 65 is the ASCII code of 'A'
	return locationOfChessFormat;
}

bool Location::isOnBoard() const {
	return (this->x >= 0 && this->x <= 7 && this->y >= 0 && this->y <= 7);
}

/* 
* return the location of the square that is down to the current square: 🔽
*/ 
Location Location::up() const {
	return Location(this->x, this->y + 1);
}

/*
* return the location of the square that is up to the current square: 🔼
*/
Location Location::down() const {
	return Location(this->x, this->y - 1);
}

/*
 * return the location of the square that is left to the current square: ◀-

 */
Location Location::left() const {
	return Location(this->x - 1, this->y);
}

/*
 * return the location of the square that is right to the current square: -▶
 */
Location Location::right() const {
	return Location(this->x + 1, this->y);
}

/*
 * return the location of the square that is up left to the current square: ↙
 */
Location Location::upLeft() const {
	return Location(this->x - 1, this->y + 1);
}

/*
 * return the location of the square that is up right to the current square: ↘
 */
Location Location::upRight() const {
	return Location(this->x + 1, this->y + 1);
}

/*
 * return the location of the square that is down left to the current square: ↖
 */
Location Location::downLeft() const {
	return Location(this->x - 1, this->y - 1);
}

/*
 * return the location of the square that is down right to the current square: ↗
 */
Location Location::downRight() const {
	return Location(this->x + 1, this->y - 1);
}
