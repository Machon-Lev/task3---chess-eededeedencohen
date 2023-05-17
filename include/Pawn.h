// Pawn.h
#pragma once
#include <vector>
#include <utility> // for std::pair
#include "Piece.h" // Include Piece.h
#include "Move.h"


class Pawn : public Piece {
public:
    Pawn(Color color, Location location, Board* board);
    ~Pawn();

    vector<Move> getAllLegalMoves() const override;
};
