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
	int getX() const;
	int getY() const;
	void moveTo(Location newLocation);
	string getLocationOfChessFormat() const;
};



