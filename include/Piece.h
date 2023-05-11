// Piece.h
#pragma once
#include <iostream>
#include <vector>
#include <utility> // for std::pair
#include <string>

// Forward declaration of Board
class Board;

enum Color { WHITE, BLACK };

class Piece {
protected:
    Color color;
    int x;
    int y;
    char symbol = 'x';
    Board* board;

public:
    Piece(Color color, int x, int y, Board* board);
    virtual ~Piece();

    Color getColor() const;
    int getX() const;
    int getY() const;
    char getSymbol() const;

    void setX(int x);
    void setY(int y);

    virtual bool isLegalMove(int x, int y) const = 0;
    virtual bool isLegalKill(int x, int y) const = 0;
    virtual void move(int x, int y) = 0;

    // Return a vector of pairs, each pair representing a legal move or kill
    virtual std::vector<std::pair<int, int>> getAllLegalMoves() const = 0;
    virtual std::vector<std::pair<int, int>> getAllKillMoves() const = 0;
};
