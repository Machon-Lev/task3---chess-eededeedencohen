// King.cpp
#include "Board.h"
#include "King.h"

King::King(Color color, Location location, Board* board) : Piece(color, location, board) {
    this->symbol = (color == WHITE) ? 'K' : 'k';
}

King::~King() {}

vector<Move> King::getAllLegalMoves() const {
    vector<Move> v;
    return v;
}

