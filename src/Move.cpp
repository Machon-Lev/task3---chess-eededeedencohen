#include "Move.h"


Move::Move()
{
	this->start = Location();
	this->end = Location();
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