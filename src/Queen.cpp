#include "Queen.h"
#include "Board.h"

Queen::Queen(Color color, Location location, Board* board) : Piece(color, location, board) {
    this->symbol = (color == WHITE) ? 'Q' : 'q';
}

Queen::~Queen() {}

vector<Move> Queen::getAllLegalMoves() const {
    vector<Move> legalMoves;

 
    for (int direction : {-1, 1}) 
    {   // case of ➡️ ⬅️
        for (int i = this->location.x + direction;board->isInside(Location(i, this->location.y)); i += direction)
        {
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
        for (int i = this->location.y + direction;board->isInside(Location(this->location.x, i)); i += direction)
        {   // case of empty square
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

    // case of ↗️, ↖️, ↘️, ↙️
    for (int dx : {-1, 1}) {
        for (int dy : {-1, 1}) {
            for (int i = this->location.x + dx, j = this->location.y + dy;
                board->isInside(Location(i, j));
                i += dx, j += dy)
            {   
                // case of empty square
                if (this->board->getPiece(Location(i, j)) == nullptr)
                {
                    legalMoves.push_back(Move(this->location, Location(i, j)));
                }
                // case is enemy piece
                else if (this->board->getPiece(Location(i, j))->getColor() != this->getColor())
                {
                    legalMoves.push_back(Move(this->location, Location(i, j), true, Location(i, j)));
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }

    return legalMoves;
}
