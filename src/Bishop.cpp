// Bishop.cpp
#include "Board.h"
#include "Bishop.h"

Bishop::Bishop(Color color, Location location, Board* board) : Piece(color, location, board) {
    this->symbol = (color == WHITE) ? 'B' : 'b';
}

Bishop::~Bishop() {}

vector<Move> Bishop::getAllLegalMoves() const {
    vector<Move> v;
    return v;
}
