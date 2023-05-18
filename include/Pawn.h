#pragma once
#include "Piece.h" 


class Pawn : public Piece {
public:
    Pawn(Color color, Location location, Board* board);
    ~Pawn();

    vector<Move> getAllLegalMoves() const override;
};
