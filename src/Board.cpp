// Board.cpp
#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

// red color for the pieces of the first player:
#define RED "\033[31m"

// green color for the pieces of the second player:
#define GREEN "\033[32m"

// reset color:
#define RESET "\033[0m"

Board::Board() : board(8, std::vector<Piece*>(8, nullptr)) {

    // Initialize white pieces:

    // Rooks:
    board[0][0] = new Rook(BLACK, 0, 0, this);
    board[7][0] = new Rook(BLACK, 7, 0, this);

    // Knights:
    board[1][0] = new Knight(BLACK, 1, 0, this);
    board[6][0] = new Knight(BLACK, 6, 0, this);

    // Bishops:
    board[2][0] = new Bishop(BLACK, 2, 0, this);
    board[5][0] = new Bishop(BLACK, 5, 0, this);

    // Queen:
    board[3][0] = new Queen(BLACK, 3, 0, this);

    // King:
    board[4][0] = new King(BLACK, 4, 0, this);

    // Pawns:
    for (int x = 0; x < 8; x++) {
		board[x][1] = new Pawn(BLACK, x, 1, this);
	}

    // Initialize black pieces:

    // Rooks:
    board[0][7] = new Rook(WHITE, 0, 7, this);
    board[7][7] = new Rook(WHITE, 7, 7, this);

    // Knights:
    board[1][7] = new Knight(WHITE, 1, 7, this);
    board[6][7] = new Knight(WHITE, 6, 7, this);

    // Bishops:
    board[2][7] = new Bishop(WHITE, 2, 7, this);
    board[5][7] = new Bishop(WHITE, 5, 7, this);

    // Queen:
    board[3][7] = new Queen(WHITE, 3, 7, this);

    // King:
    board[4][7] = new King(WHITE, 4, 7, this);

    // Pawns:
    for (int x = 0; x < 8; x++) {
        board[x][6] = new Pawn(WHITE, x, 6, this);
    }

    // Initialize empty squares:
    for (int y = 2; y < 6; y++) {
        for (int x = 0; x < 8; x++) {
			board[x][y] = nullptr;
		}
	}

    this->turn = WHITE;
}

Board::~Board() {
    // Clean up board...
    for (auto& row : board) {
        for (auto& piece : row) {
            delete piece;
            piece = nullptr;
        }
    }
}

Piece* Board::getPiece(int x, int y) const {
    return board[x][y];
}

void Board::setPiece(Piece* piece, int x, int y) {
    board[x][y] = piece;
}

bool Board::isEmpty(int x, int y) const {
    return board[x][y] == nullptr;
}

bool Board::isInside(int x, int y) const {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void Board::PrintAllPieces() const {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (board[x][y] != nullptr) {
				cout << board[x][y]->getSymbol() << ": (" << x << ", " << y << ")" << endl;
			}
		}
	}
}

// print the board:
void Board::PrintBoard() const {
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (board[col][row] == nullptr)
            {
				cout << "- ";
			}
            else
            {
                if (board[col][row]->getColor() == WHITE)
                {
					cout << GREEN << board[col][row]->getSymbol() << " " << RESET;
				}
                else
                {
					cout << RED << board[col][row]->getSymbol() << " " << RESET;
				}
			}
		}
        cout << endl;
    }
}



