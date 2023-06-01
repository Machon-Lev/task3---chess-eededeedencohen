#include "Board.h"
#include "Pawn.h"


Pawn::Pawn(Color color, Location location, Board* board) : Piece(color, location, board) {
	this->symbol = (color == WHITE) ? 'P' : 'p';
}

Pawn::~Pawn() {}

vector<Move> Pawn::getAllLegalMoves() const {
	vector<Move> legalMoves;

	// case pawn is white:
	if (this->color == WHITE)
	{
		// case move one step forward is legal: 🔼
		if (this->location.down().isOnBoard() && this->board->getPiece(this->location.down()) == nullptr)
		{
			legalMoves.push_back(Move(this->location, this->location.down()));
		}

		// case move two steps forward is legal: 🔼🔼
		if (this->location.down().down().isOnBoard() && this->board->getPiece(this->location.down()) == nullptr 
			&& this->board->getPiece(this->location.down().down()) == nullptr && this->location.y == 6)
		{
			legalMoves.push_back(Move(this->location, this->location.down().down()));
		}

		// case capture left is legal: ↖
		if (this->location.downLeft().isOnBoard() && this->board->getPiece(this->location.downLeft()) != nullptr
			&& this->board->getPiece(this->location.downLeft())->getColor() != this->color)
		{
			legalMoves.push_back(Move(this->location, this->location.downLeft(), true, this->location.downLeft()));
		}

		// case capture right is legal: ↗
		if (this->location.downRight().isOnBoard() && this->board->getPiece(this->location.downRight()) != nullptr
			&& this->board->getPiece(this->location.downRight())->getColor() != this->color)
		{
			legalMoves.push_back(Move(this->location, this->location.downRight(), true, this->location.downRight()));
		}

		// case en passant left is legal: ↖
		if (this->location.downLeft().isOnBoard() && this->board->getPiece(this->location.downLeft()) == nullptr
			&& this->board->getPiece(this->location.left()) != nullptr
			&& this->board->getPiece(this->location.left())->getColor() != this->color
			&& this->board->getPiece(this->location.left())->getSymbol() == 'p'
			&& this->board->CanEnPassant() && this->board->getEnPassantLocation() == this->location.downLeft())
		{
			legalMoves.push_back(Move(this->location, this->location.downLeft(), true, this->location.left()));
		}

		// case en passant right is legal: ↗
		if (this->location.downRight().isOnBoard() && this->board->getPiece(this->location.downRight()) == nullptr
			&& this->board->getPiece(this->location.right()) != nullptr
			&& this->board->getPiece(this->location.right())->getColor() != this->color
			&& this->board->getPiece(this->location.right())->getSymbol() == 'p'
			&& this->board->CanEnPassant() && this->board->getEnPassantLocation() == this->location.downRight())
		{
			legalMoves.push_back(Move(this->location, this->location.downRight(), true, this->location.right()));
		}

	}
	else // case pawn is black:
	{
		// case move one step forward is legal: 🔽
		if (this->location.up().isOnBoard() && this->board->getPiece(this->location.up()) == nullptr)
		{
			legalMoves.push_back(Move(this->location, this->location.up()));
		}

		// case move two steps forward is legal: 🔽🔽
		if (this->location.up().up().isOnBoard() && this->board->getPiece(this->location.up()) == nullptr
			&& this->board->getPiece(this->location.up().up()) == nullptr && this->location.y == 1)
		{
			legalMoves.push_back(Move(this->location, this->location.up().up()));
		}

		// case capture left is legal: ↙️
		if (this->location.upLeft().isOnBoard() && this->board->getPiece(this->location.upLeft()) != nullptr
			&& this->board->getPiece(this->location.upLeft())->getColor() != this->color)
		{
			legalMoves.push_back(Move(this->location, this->location.upLeft(), true, this->location.upLeft()));
		}

		// case capture right is legal: ↘️
		if (this->location.upRight().isOnBoard() && this->board->getPiece(this->location.upRight()) != nullptr
			&& this->board->getPiece(this->location.upRight())->getColor() != this->color)
		{
			legalMoves.push_back(Move(this->location, this->location.upRight(), true, this->location.upRight()));
		}

		// case en passant left is legal: ↙️
		if (this->location.upLeft().isOnBoard() && this->board->getPiece(this->location.upLeft()) == nullptr
			&& this->board->getPiece(this->location.left()) != nullptr
			&& this->board->getPiece(this->location.left())->getColor() != this->color
			&& this->board->getPiece(this->location.left())->getSymbol() == 'P'
			&& this->board->CanEnPassant() && this->board->getEnPassantLocation() == this->location.upLeft())
		{
			legalMoves.push_back(Move(this->location, this->location.upLeft(), true, this->location.left()));
		}

		// case en passant right is legal: ↘️
		if (this->location.upRight().isOnBoard() && this->board->getPiece(this->location.upRight()) == nullptr
			&& this->board->getPiece(this->location.right()) != nullptr
			&& this->board->getPiece(this->location.right())->getColor() != this->color
			&& this->board->getPiece(this->location.right())->getSymbol() == 'P'
			&& this->board->CanEnPassant() && this->board->getEnPassantLocation() == this->location.upRight())
		{
			legalMoves.push_back(Move(this->location, this->location.upRight(), true, this->location.right()));
		}
	}
	return legalMoves;
}