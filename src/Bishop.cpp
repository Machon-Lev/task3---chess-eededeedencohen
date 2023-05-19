#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(Color color, Location location, Board* board) : Piece(color, location, board) {
    this->symbol = (color == WHITE) ? 'B' : 'b';
}


Bishop::~Bishop() {}

vector<Move> Bishop::getAllLegalMoves() const {
    vector<Move> legalMoves;

    for (int dx : {-1, 1} ) {
        for (int dy : {-1, 1}) {
            for (int i = this->location.x + dx, j = this->location.y + dy;
                this->board->isInside(Location(i, j));
                i += dx, j += dy)
            {
                // case the square is empty
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
