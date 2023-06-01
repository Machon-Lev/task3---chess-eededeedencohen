#pragma once
#include "Piece.h" 


class Queen : public Piece {
public:
    Queen(Color color, Location location, Board* board);
    ~Queen();

    vector<Move> getAllLegalMoves() const override;

};
