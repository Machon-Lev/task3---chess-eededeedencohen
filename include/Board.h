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
    bool whitePlayerHasMoves;
    bool blackPlayerHasMoves;

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

    // =============================================
    //  methodes for adapting the board to the GUI:
    //==============================================
    
    // code 11: the source location is empty
    bool sourceLocationIsEmpty(Location sourceLocation) const;

    // code 12: the source location is opponent piece
    bool sourceLocationIsOpponentPiece(Location sourceLocation, Color player) const;

    // code 13: the destination location is player piece
    bool destinationLocationIsPlayerPiece(Location destinationLocation, Color player) const;

    // code 21: the Move is illegal
    bool MoveIsNotLegal(Move move) const;

    // code 31: the Move will cause checkmate
    bool MoveWillCauseCheckmate(Move move, Color player) const;

    // code 41: move is legal and cause check
    bool MoveIsLegalAndCauseCheck(Move move, Color player) const;

    // code 42: move is legal and not cause check
    bool MoveIsLegalAndNotCauseCheck(Move move, Color player) const;

};
