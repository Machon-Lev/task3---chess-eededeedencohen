#include "Board.h"
#include "Pawn.h"

Pawn::Pawn(Color color, Location location, Board* board) : Piece(color, location, board) {
	this->symbol = (color == WHITE) ? 'P' : 'p';
}

Pawn::~Pawn() {}

vector<Move> Pawn::getAllLegalMoves() const {
	vector<Move> legalMoves;

	return legalMoves;
}