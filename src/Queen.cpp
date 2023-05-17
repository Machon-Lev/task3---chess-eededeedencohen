// Queen.cpp
#include "Board.h"
#include "Queen.h"

Queen::Queen(Color color, Location location, Board* board) : Piece(color, location, board) {
    this->symbol = (color == WHITE) ? 'Q' : 'q';
}

Queen::~Queen() {}

vector<Move> Queen::getAllLegalMoves() const {
    vector<Move> v;
    return v;
}

