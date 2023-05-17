// Knight.h
#pragma once
#include <vector>
#include <utility> // for std::pair
#include "Piece.h" // Include Piece.h
#include "Move.h"


class Knight : public Piece {
public:
    Knight(Color color, Location location, Board* board);
    ~Knight();

    vector<Move> getAllLegalMoves() const override;
};
