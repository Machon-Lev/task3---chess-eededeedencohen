// Rook.h
#pragma once
#include <vector>
using std::vector;
#include <utility> // for std::pair
#include "Piece.h" // Include Piece.h
#include "Move.h"

class Rook : public Piece {
public:
    Rook(Color color, Location location, Board* board);
    ~Rook();

    vector<Move> getAllLegalMoves() const override;
};
