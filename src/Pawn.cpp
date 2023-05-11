#include "Board.h"
#include "Pawn.h"

Pawn::Pawn(Color color, int x, int y, Board* board) : Piece(color, x, y, board) {
	// if the color is while: p else P:
	if (color == WHITE) {
		this->symbol = 'P';
	}
	else {
		this->symbol = 'p';
	}
}

Pawn::~Pawn() {}

bool Pawn::isLegalMove(int x, int y) const {
	return true;
}

bool Pawn::isLegalKill(int x, int y) const {
	return true;
}

void Pawn::move(int x, int y) {
	return;
}

std::vector<std::pair<int, int>> Pawn::getAllLegalMoves() const {
	std::vector<std::pair<int, int>> v;
	return v;
}

std::vector <std::pair<int, int>> Pawn::getAllKillMoves() const {
	std::vector<std::pair<int, int>> v;
	return v;
}


