#include "Board.h"
#include "Knight.h"

Knight::Knight(Color color, Location location, Board* board) : Piece(color, location, board) {
    this->symbol = (color == WHITE) ? 'N' : 'n';
}

Knight::~Knight() {}

vector<Move> Knight::getAllLegalMoves() const {
    vector<Move> legalMoves;

    // There are 8 possible L shaped directions for a knight
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    for (int i = 0; i < 8; i++) {
        int newX = this->location.x + dx[i];
        int newY = this->location.y + dy[i];

        // Check if the new location is within the board
        if (board->isInside(Location(newX, newY)))
        {
            // case the end location is empty square:
            if (board->getPiece(Location(newX, newY)) == nullptr)
            {
                legalMoves.push_back(Move(this->location, Location(newX, newY)));
            }
            // case the end location is an enemy piece:
            else if (board->getPiece(Location(newX, newY))->getColor() != this->color)
            {
                legalMoves.push_back(Move(this->location, Location(newX, newY), true, Location(newX, newY)));
            }
        }
    }

    return legalMoves;
}

