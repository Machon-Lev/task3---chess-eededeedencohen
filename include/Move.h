#pragma once
#include "Location.h"

struct Move
{
	Move(); // default c-tor
	Move(Location start, Location end, bool isEat, Location eat); // c-tor
	~Move(); // d-tor

	Location start; // the location of the piece before the move
	Location end; // the location of the piece after the move
	bool isEat; //  if there is a piece that can be eaten in the end Move
	Location eat; // the location of the piece that can be eaten in the end Move
};


