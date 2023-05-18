#include <iostream>
#include "Move.h"


Move::Move()
{
	this->start = Location();
	this->end = Location();
	this->isEat = false;
	this->eat = Location();
}

Move::Move(Location start, Location end)
{
	this->start = start;
	this->end = end;
	this->isEat = false;
	this->eat = Location();
}

Move::Move(Location start, Location end, bool isEat, Location eat)
{
	this->start = start;
	this->end = end;
	this->isEat = isEat;
	this->eat = eat;
}

Move::~Move() {}

//implement friend std::ostream& operator<<(std::ostream& os, const Move& move);
std::ostream& operator<<(std::ostream& os, const Move& move)
{
	os << "Move from " << move.start << " to " << move.end;
	if (move.isEat)
	{
		os << " and eat " << move.eat;
	}
	return os;
}
