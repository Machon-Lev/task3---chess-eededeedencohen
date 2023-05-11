// Piece.cpp
#include "Piece.h"
#include "Board.h"

Piece::Piece(Color color, int x, int y, Board* board) {
    this->y = y;
    this->x = x;
    this->color = color;
    this->board = board;
}

Piece::~Piece() {}

Color Piece::getColor() const {
    return this->color;
}

int Piece::getX() const {
    return this->x;
}

int Piece::getY() const {
    return this->y;
}

char Piece::getSymbol() const {
    return this->symbol;
}

void Piece::setX(int x) {
    this->x = x;
}

void Piece::setY(int y) {
    this->y = y;
}
