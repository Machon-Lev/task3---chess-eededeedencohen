// Bishop.h
#pragma once
#include <vector>
#include <utility> // for std::pair
#include "Piece.h" // Include Piece.h
#include "Move.h"


class Bishop : public Piece {
public:
    Bishop(Color color, Location location, Board* board);
    ~Bishop();

    vector<Move> getAllLegalMoves() const override;
};
