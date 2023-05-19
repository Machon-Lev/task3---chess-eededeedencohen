#include "Board.h"
#include "King.h"

King::King(Color color, Location location, Board* board) : Piece(color, location, board) {
    this->symbol = (color == WHITE) ? 'K' : 'k';
}


King::~King() {}

vector<Move> King::getAllLegalMoves() const {
    vector<Move> legalMoves;

    // The 8 directions a King can move: (dx, dy)
    int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

    for (int i = 0; i < 8; i++)
    {
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
