// Rook.cpp
#include "Rook.h"
#include "Board.h"
#include <iostream>
using std::cout;
using std::endl;

Rook::Rook(Color color, Location location, Board* board) : Piece(color, location, board) {
    this->symbol = (color == WHITE) ? 'R' : 'r';
}

Rook::~Rook() {}

vector<Move> Rook::getAllLegalMoves() const {
    vector<Move> v;
    return v;
}






