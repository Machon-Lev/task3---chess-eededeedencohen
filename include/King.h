#pragma once
#include "Piece.h"



class King : public Piece {
public:
    King(Color color, Location location, Board* board);
    ~King();

    vector<Move> getAllLegalMoves() const override;
};
