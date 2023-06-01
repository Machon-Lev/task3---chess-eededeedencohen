#pragma once
#include <iostream>
#include <vector>
using std::vector;
#include <string>
#include "Move.h"
#include "Location.h"


// Forward declaration of Board
class Board;

enum Color { WHITE, BLACK ,NONE};

class Piece {
protected:
    Color color;
    Location location;
    char symbol = 'x';
    Board* board;

public:
    Piece(Color color, Location location, Board* board);
    virtual ~Piece();


    Color getColor() const;
    Location getLocation() const;
    char getSymbol() const;
    void move(Location endLocation);
    virtual vector<Move> getAllLegalMoves() const = 0;    
};
