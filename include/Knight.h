#pragma once
#include "Piece.h" 



class Knight : public Piece {
public:
    Knight(Color color, Location location, Board* board);
    ~Knight();

    vector<Move> getAllLegalMoves() const override;
};
