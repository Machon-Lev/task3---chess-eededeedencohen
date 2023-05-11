// Pawn.h
#pragma once
#include <vector>
#include <utility> // for std::pair
#include "Piece.h" // Include Piece.h

class Pawn : public Piece {
public:
    Pawn(Color color, int x, int y, Board* board);
    ~Pawn();

    bool isLegalMove(int x, int y) const override;
    bool isLegalKill(int x, int y) const override;
    void move(int x, int y) override;

    // Override to return a vector of pairs, each pair representing a legal move or kill
    std::vector<std::pair<int, int>> getAllLegalMoves() const override;
    std::vector<std::pair<int, int>> getAllKillMoves() const override;
};
