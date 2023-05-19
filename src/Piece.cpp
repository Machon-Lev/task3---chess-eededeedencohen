#include "Piece.h"
#include "Board.h"

Piece::Piece(Color color, Location location, Board* board) {
    this->location = location;
    this->color = color;
    this->board = board;
}


Piece::~Piece() {}

Color Piece::getColor() const {
    return this->color;
}

Location Piece::getLocation() const {
	return this->location;
}

char Piece::getSymbol() const {
    return this->symbol;
}

void Piece::move(Location endLocation)
{
    this->location.moveTo(endLocation);
}






