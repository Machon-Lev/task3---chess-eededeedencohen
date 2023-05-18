#pragma once
#include "Piece.h" 


class Bishop : public Piece {
public:
    Bishop(Color color, Location location, Board* board);
    ~Bishop();

    vector<Move> getAllLegalMoves() const override;
};
