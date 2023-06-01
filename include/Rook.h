#pragma once
#include "Piece.h" 

class Rook : public Piece {
public:
    Rook(Color color, Location location, Board* board);
    ~Rook();

    vector<Move> getAllLegalMoves() const override;
};
