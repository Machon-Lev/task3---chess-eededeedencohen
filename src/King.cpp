// King.cpp
#include "Board.h"
#include "King.h"

King::King(Color color, int x, int y, Board* board) : Piece(color, x, y, board) {
    this->symbol = (color == WHITE) ? 'K' : 'k';
}

King::~King() {}

bool King::isLegalMove(int x, int y) const {
    return true;
}

bool King::isLegalKill(int x, int y) const {
    return true;
}

void King::move(int x, int y) {
    return;
}

std::vector<std::pair<int, int>> King::getAllLegalMoves() const {
    std::vector<std::pair<int, int>> v;
    return v;
}

std::vector<std::pair<int, int>> King::getAllKillMoves() const {
    std::vector<std::pair<int, int>> v;
    return v;
}