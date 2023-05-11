// Knight.cpp
#include "Board.h"
#include "Knight.h"

Knight::Knight(Color color, int x, int y, Board* board) : Piece(color, x, y, board) {
    this->symbol = (color == WHITE) ? 'N' : 'n';
}

Knight::~Knight() {}

bool Knight::isLegalMove(int x, int y) const {
    return true;
}

bool Knight::isLegalKill(int x, int y) const {
    return true;
}

void Knight::move(int x, int y) {
    return;
}

std::vector<std::pair<int, int>> Knight::getAllLegalMoves() const {
    std::vector<std::pair<int, int>> v;
    return v;
}

std::vector<std::pair<int, int>> Knight::getAllKillMoves() const {
    std::vector<std::pair<int, int>> v;
    return v;
}
