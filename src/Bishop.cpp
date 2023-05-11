// Bishop.cpp
#include "Board.h"
#include "Bishop.h"

Bishop::Bishop(Color color, int x, int y, Board* board) : Piece(color, x, y, board) {
    this->symbol = (color == WHITE) ? 'B' : 'b';
}

Bishop::~Bishop() {}

bool Bishop::isLegalMove(int x, int y) const {
    return true;
}

bool Bishop::isLegalKill(int x, int y) const {
    return true;
}

void Bishop::move(int x, int y) {
    return;
}

std::vector<std::pair<int, int>> Bishop::getAllLegalMoves() const {
    std::vector<std::pair<int, int>> v;
    return v;
}

std::vector<std::pair<int, int>> Bishop::getAllKillMoves() const {
    std::vector<std::pair<int, int>> v;
    return v;
}
