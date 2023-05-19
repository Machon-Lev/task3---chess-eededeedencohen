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
    vector<Move> legalMoves;

    for (int direction : {-1, 1})
    {
        // case of ➡️ ⬅️
        for (int i = this->location.x + direction; board->isInside(Location(i, this->location.y)); i += direction)
        {
            // case of empty square
            if (this->board->getPiece(Location(i, this->location.y)) == nullptr)
            {
                legalMoves.push_back(Move(this->location, Location(i, this->location.y)));
            }
            // case is enemy piece
            else if (this->board->getPiece(Location(i, this->location.y))->getColor() != this->getColor())
            {
                legalMoves.push_back(Move(this->location, Location(i, this->location.y), true, Location(i, this->location.y)));
                break;
            }
            else
            {
                break;
            }
        }

        // case of 🔼, 🔽
        for (int i = this->location.y + direction; board->isInside(Location(this->location.x, i)); i += direction)
        {
            // case of empty square
            if (this->board->getPiece(Location(this->location.x, i)) == nullptr)
            {
                legalMoves.push_back(Move(this->location, Location(this->location.x, i)));
            }
            // case is enemy piece
            else if (this->board->getPiece(Location(this->location.x, i))->getColor() != this->getColor())
            {
                legalMoves.push_back(Move(this->location, Location(this->location.x, i), true, Location(this->location.x, i)));
                break; 
            }
            else
            {
                break;
            }
        }
    }
    return legalMoves;
}
