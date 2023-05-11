// Queen.cpp
#include "Board.h"
#include "Queen.h"

Queen::Queen(Color color, int x, int y, Board* board) : Piece(color, x, y, board) {
    this->symbol = (color == WHITE) ? 'Q' : 'q';
}

Queen::~Queen() {}

bool Queen::isLegalMove(int x, int y) const {
    return true;
}

bool Queen::isLegalKill(int x, int y) const {
    return true;
}

void Queen::move(int x, int y) {
    return;
}

std::vector<std::pair<int, int>> Queen::getAllLegalMoves() const {
    std::vector<std::pair<int, int>> v;
    return v;
}

std::vector<std::pair<int, int>> Queen::getAllKillMoves() const {
    std::vector<std::pair<int, int>> v;
    return v;
}
