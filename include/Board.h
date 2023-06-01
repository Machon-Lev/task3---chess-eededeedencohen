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

    // get the piece in the given location
    Piece* getPiece(Location location) const;

    // set the piece in the given location
    void setPiece(Piece* piece, Location location);

    // return true if the given location is empty
    bool isEmpty(Location location) const;

    // return true if the given location is inside the board
    bool isInside(Location location) const;

    // print the board to the console
    void PrintBoard() const;

    // print all the pieces and their locations to the console
    void PrintAllPieces() const;

    // return WHITe for white player turn and BLACK for black player turn
    Color getTurn() const;

    // replace the ture: if turn is white then replace it to black and if turn is black then replace it to white
    void switchTurn();

    // return true if enPassant is legal this turn
    bool CanEnPassant() const;

    // set the location of the square to move in order to do enPassant next turn
    void setEnPassantLocation(Location en_passant_location);

    // return the location of the square to move in order to do enPassant this turn
    Location getEnPassantLocation() const;

    // return true if the player has legal moves - its regard to the move that not cause check to the king of the player
    void printAllPieceLegalMoves(Location pieceLocation) const;

    // set all the location to be empty
    void cleanBoard();

    // received a string of pieces and fill the board with the pieces (same formal like the GUI)
    void testBoard(string boardInStringFormat);

    // set enpassant to be illegal
    void setEnPassantFalse();

    // helper function. check if the given move eat the opponent king
    bool isMoveToOpponentKing(Move move) const;

    // helper function. check if there is a move that can eat the opponent king
    bool isKingCapture(Color playerOfTheKing) const;

    // return all the legal moves of the player - after removing the moves that cause check to the king
    vector<Move> getAllLegalMoves(Color player);

    // move the piece in the given move
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
    bool MoveWillCauseCheckmate(Move move, Color player);

    //----------------------------------------------------------------------------------------
    // code 41+42+52: move is legal + move the piece
    // 41 - move is check move - the moving playey check the opponent king and win the game
    // 42 - regular move
    // 52 - move is en passant move
    //----------------------------------------------------------------------------------------
    int CheckIfLegalMove(Move move, Color player);

    // convert the string move from the gui to Move object
    Move convertStringMoveToMove(string moveInStringFormat);

    // helper function for the GUI - convert the move to code
    int getCodeOfMoving(Move move);

};
