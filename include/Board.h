#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Piece.h" 
#include "Location.h"
using std::cout;
using std::endl;
using std::string;

class Board {
private:
    std::vector<std::vector<Piece*>> board;
    Color turn;
    bool can_en_passant;
    Location en_passant_location;


public:
    Board();
    ~Board();
    Board(const Board& other);

    // Add other necessary methods...
    Piece* getPiece(Location location) const;
    void setPiece(Piece* piece, Location location);
    bool isEmpty(Location location) const;
    bool isInside(Location location) const;
    void PrintBoard() const;
    void PrintAllPieces() const;
    Color getTurn() const;
    void switchTurn();
    bool CanEnPassant() const;
    void setEnPassantLocation(Location en_passant_location);
    Location getEnPassantLocation() const;
    void printAllPieceLegalMoves(Location pieceLocation) const;
    void cleanBoard();
    void testBoard(string boardInStringFormat);
    void setEnPassantFalse();
    bool isMoveToOpponentKing(Move move) const;
    bool isKingCapture(Color playerOfTheKing) const;
    vector<Move> getAllLegalMoves(Color player);
    void movePiece(Move move);
};
