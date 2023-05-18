#pragma once
#include <string>
using std::string;

struct Location
{
	int x;
	int y;
	Location();
	Location(int x, int y);
	~Location();
	bool operator==(const Location& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Location& location);
	int getX() const;
	int getY() const;
	void moveTo(Location newLocation);
	string getLocationOfChessFormat() const;
	bool isOnBoard() const;
	Location up() const;
	Location down() const;
	Location left() const;
	Location right() const;
	Location upLeft() const;
	Location upRight() const;
	Location downLeft() const;
	Location downRight() const;
};



