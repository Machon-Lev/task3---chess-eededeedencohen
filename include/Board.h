// Board.h
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Piece.h" // Include Piece.h here
using std::cout;
using std::endl;

class Board {
private:
    std::vector<std::vector<Piece*>> board;
    Color turn;

public:
    Board();
    ~Board();
    // Add other necessary methods...
    Piece* getPiece(int x, int y) const;
    void setPiece(Piece* piece, int x, int y);
    bool isEmpty(int x, int y) const;
    bool isInside(int x, int y) const;
    void PrintBoard() const;
    void PrintAllPieces() const;
};
