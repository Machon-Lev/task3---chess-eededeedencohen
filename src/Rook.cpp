// Rook.cpp
#include "Rook.h"
#include "Board.h"
#include <iostream>
using std::cout;
using std::endl;

Rook::Rook(Color color, int x, int y, Board* board) : Piece(color, x, y, board) {
    this->symbol = (color == WHITE) ? 'R' : 'r';
}

Rook::~Rook() {}

bool Rook::isLegalMove(int x, int y) const {
    // Rook can move only horizontally or vertically
    if (this->x != x && this->y != y) {
        return false;
    }

    // Check if the path is clear
    if (this->x == x) {
        // Moving vertically
        int start = std::min(this->y, y);
        int end = std::max(this->y, y);
        for (int i = start + 1; i < end; ++i) {
            if (!this->board->isEmpty(x, i)) {
                return false;
            }
        }
    }
    else {
        // Moving horizontally
        int start = std::min(this->x, x);
        int end = std::max(this->x, x);
        for (int i = start + 1; i < end; ++i) {
            if (!this->board->isEmpty(i, y)) {
                return false;
            }
        }
    }

    // Check if the destination is empty or contains an enemy piece
    Piece* destination = this->board->getPiece(x, y);
    if (destination == nullptr || destination->getColor() != this->color) {
        return true;
    }

    return false;
}

bool Rook::isLegalKill(int x, int y) const {
    // For Rook, killing move is the same as legal move
    return isLegalMove(x, y);
}

void Rook::move(int x, int y) {
    if (isLegalMove(x, y)) {
        // If there is a piece at destination, delete it
        Piece* destination = this->board->getPiece(x, y);
        if (destination != nullptr) {
            delete destination;
        }

        // Move the rook
        this->board->setPiece(this, x, y);
        this->board->setPiece(nullptr, this->x, this->y);
        this->x = x;
        this->y = y;
    }
    else {
        // Throw an error or something
    }
}

std::vector<std::pair<int, int>> Rook::getAllLegalMoves() const {
    std::vector<std::pair<int, int>> v;

    // Vertical and horizontal directions
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };

    // Try all directions
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j < 8; ++j) {
            int newX = this->x + dx[i] * j;
            int newY = this->y + dy[i] * j;

            if (!this->board->isInside(newX, newY)) {
                break;
            }

            if (this->isLegalMove(newX, newY)) {
                v.push_back({ newX, newY });

                if (!this->board->isEmpty(newX, newY)) {
                    // Stop if there is a piece in the way
                    break;
                }
            }
            else {
                break;
            }
        }
    }

    return v;
 }


std::vector<std::pair<int, int>> Rook::getAllKillMoves() const {
    std::vector<std::pair<int, int>> v;

    // Vertical and horizontal directions
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };

    // Try all directions
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j < 8; ++j) {
            int newX = this->x + dx[i] * j;
            int newY = this->y + dy[i] * j;

            if (!this->board->isInside(newX, newY)) {
                break;
            }

            if (this->isLegalKill(newX, newY)) {
                v.push_back({ newX, newY });

                if (!this->board->isEmpty(newX, newY)) {
                    // Stop if there is a piece in the way
                    break;
                }
            }
            else {
                break;
            }
        }
    }

    return v;
}






