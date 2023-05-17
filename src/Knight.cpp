// Knight.cpp
#include "Board.h"
#include "Knight.h"

Knight::Knight(Color color, Location location, Board* board) : Piece(color, location, board) {
    this->symbol = (color == WHITE) ? 'N' : 'n';
}

Knight::~Knight() {}

vector<Move> Knight::getAllLegalMoves() const {
    vector<Move> v;
    return v;
}

