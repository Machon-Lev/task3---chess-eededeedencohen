// King.h
#pragma once
#include <vector>
#include <utility> // for std::pair
#include "Piece.h" // Include Piece.h
#include "Move.h"


class King : public Piece {
public:
    King(Color color, Location location, Board* board);
    ~King();

    vector<Move> getAllLegalMoves() const override;
};
