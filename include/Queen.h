// Queen.h
#pragma once
#include <vector>
#include <utility> // for std::pair
#include "Piece.h" // Include Piece.h
#include "Move.h"


class Queen : public Piece {
public:
    Queen(Color color, Location location, Board* board);
    ~Queen();

    vector<Move> getAllLegalMoves() const override;

};
