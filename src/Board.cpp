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
    board[0][0] = new Rook(BLACK, Location(0, 0), this);
    board[7][0] = new Rook(BLACK, Location(7, 0), this);

    // Knights:
    board[1][0] = new Knight(BLACK, Location(1, 0), this);
    board[6][0] = new Knight(BLACK, Location(6, 0), this);


    // Bishops:
    board[2][0] = new Bishop(BLACK, Location(2, 0), this);
    board[5][0] = new Bishop(BLACK, Location(5, 0), this);

    // Queen:
    board[3][0] = new Queen(BLACK, Location(3, 0), this);

    // King:
    board[4][0] = new King(BLACK, Location(4, 0), this);

    // Pawns:
    for (int x = 0; x < 8; x++) {
        board[x][1] = new Pawn(BLACK, Location(x, 1), this);
	}

    // Initialize black pieces:

    // Rooks:
    board[0][7] = new Rook(WHITE, Location(0, 7), this);
    board[7][7] = new Rook(WHITE, Location(7, 7), this);


    // Knights:
    board[1][7] = new Knight(WHITE, Location(1, 7), this);
    board[6][7] = new Knight(WHITE, Location(6, 7), this);

    // Bishops:
    board[2][7] = new Bishop(WHITE, Location(2, 7), this);
    board[5][7] = new Bishop(WHITE, Location(5, 7), this);


    // Queen:
    board[3][7] = new Queen(WHITE, Location(3, 7), this);

    // King:
    board[4][7] = new King(WHITE, Location(4, 7), this);

    // Pawns:
    for (int x = 0; x < 8; x++) {
        board[x][6] = new Pawn(WHITE, Location(x, 6), this);
    }

    // Initialize empty squares:
    for (int y = 2; y < 6; y++) {
        for (int x = 0; x < 8; x++) {
			board[x][y] = nullptr;
		}
	}

    this->turn = WHITE;
    this->can_en_passant = false;
    this->en_passant_location = Location(-1, -1); //Location(-1, -1);
    this->blackPlayerHasMoves = true;
    this->whitePlayerHasMoves = true;
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

// copy constructor:
Board::Board(const Board& other) : board(8, std::vector<Piece*>(8, nullptr)) {
	// copy the board:
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++)
        {
            if (other.board[x][y] != nullptr) {
                if (dynamic_cast<Pawn*>(other.board[x][y]) != nullptr) {
                    Color color = other.board[x][y]->getColor();
                    Location location = other.board[x][y]->getLocation();
                    this->board[x][y] = new Pawn(color, location, this);
				}
                else if (dynamic_cast<Knight*>(other.board[x][y]) != nullptr) {
                     Color color = other.board[x][y]->getColor();
                     Location location = other.board[x][y]->getLocation();
                     this->board[x][y] = new Knight(color, location, this);
                }
                else if (dynamic_cast<Bishop*>(other.board[x][y]) != nullptr) {
                    Color color = other.board[x][y]->getColor();
                    Location location = other.board[x][y]->getLocation();
                    this->board[x][y] = new Bishop(color, location, this);
				}
                else if (dynamic_cast<Rook*>(other.board[x][y]) != nullptr) {
					Color color = other.board[x][y]->getColor();
					Location location = other.board[x][y]->getLocation();
					this->board[x][y] = new Rook(color, location, this);
				}
                else if (dynamic_cast<Queen*>(other.board[x][y]) != nullptr) {
                    Color color = other.board[x][y]->getColor();
                    Location location = other.board[x][y]->getLocation();
                    this->board[x][y] = new Queen(color, location, this);
				}
                else if (dynamic_cast<King*>(other.board[x][y]) != nullptr) {
                    Color color = other.board[x][y]->getColor();
                    Location location = other.board[x][y]->getLocation();
                    this->board[x][y] = new King(color, location, this);
				}
                else {
					this->board[x][y] = nullptr;
                }

                this->turn = other.turn;
                this->can_en_passant = other.can_en_passant;
                this->en_passant_location = other.en_passant_location;

			}
		}
	}
	// copy the turn:
	this->turn = other.turn;
	// copy the en passant:
	this->can_en_passant = other.can_en_passant;
	this->en_passant_location = other.en_passant_location;
}

















Piece* Board::getPiece(Location location) const {
    return board[location.getX()][location.getY()];
}

void Board::setPiece(Piece* piece, Location location) {
    board[location.getX()][location.getY()] = piece;
}

bool Board::isEmpty(Location location) const {
    return board[location.getX()][location.getY()] == nullptr;
}

bool Board::isInside(Location location) const {
    return location.getX() >= 0 && location.getX() < 8 && location.getY() >= 0 && location.getY() < 8;
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
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (int row = 0; row < 8; row++)
    {
        cout << row << " ";
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
        cout << row << " ";
        cout << endl;
    }
    cout << "  0 1 2 3 4 5 6 7" << endl;
}


Color Board::getTurn() const {
	return this->turn;
}

void Board::switchTurn() {
    if (this->turn == WHITE) {
		this->turn = BLACK;
	}
    else {
		this->turn = WHITE;
	}
}

bool Board::CanEnPassant() const {
	return this->can_en_passant;
}

void Board::setEnPassantLocation(Location en_passant_location) {
	this->en_passant_location = en_passant_location;
	this->can_en_passant = true;
}

Location Board::getEnPassantLocation() const {
	return this->en_passant_location;
}

void Board::printAllPieceLegalMoves(Location location) const {
    vector<Move> legalMoves;
    Piece* piece = getPiece(location);
    if (piece != nullptr) {
		legalMoves = piece->getAllLegalMoves();
        for (Move move : legalMoves)
        {
            cout << move << endl;
        }
        
    }
}

// replace the pieces with nullptr:
void Board::cleanBoard()
{
    for (auto& row : board)
    {
        for (auto& piece : row)
        {
			delete piece;
			piece = nullptr;
		}
	}
}


void Board::testBoard(string boardInStringFormat) {
	cleanBoard();

    // remove all the '|' from the string:
    boardInStringFormat.erase(remove(boardInStringFormat.begin(), boardInStringFormat.end(), '|'), boardInStringFormat.end());

    // initialization the board according to the string:
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            switch (boardInStringFormat[row * 8 + col])
            {
                case 'r':
					board[col][row] = new Rook(BLACK, Location(col, row), this);
					break;
				case 'n':
                    board[col][row] = new Knight(BLACK, Location(col, row), this);
                    break;
                case 'b':
                    board[col][row] = new Bishop(BLACK, Location(col, row), this);
					break;
                case 'q':
					board[col][row] = new Queen(BLACK, Location(col, row), this);
                    break;
				case 'k':
                    board[col][row] = new King(BLACK, Location(col, row), this);
					break;
                case 'p':
					board[col][row] = new Pawn(BLACK, Location(col, row), this);
                    break;
				case 'R':
                    board[col][row] = new Rook(WHITE, Location(col, row), this);
                    break;
                case 'N':
                    board[col][row] = new Knight(WHITE, Location(col, row), this);
                    break;
                case 'B':
                    board[col][row] = new Bishop(WHITE, Location(col, row), this);
					break;
                case 'Q':
					board[col][row] = new Queen(WHITE, Location(col, row), this);
                    break;
                case 'K':
                    board[col][row] = new King(WHITE, Location(col, row), this);
                    break;
                case 'P':
                    board[col][row] = new Pawn(WHITE, Location(col, row), this);
                    break;
                default:
                    board[col][row] = nullptr;
					break;
            }
        }
    }

}

void Board::setEnPassantFalse() {
	this->can_en_passant = false;
    this->en_passant_location = Location(-1, -1);
}

bool Board::isMoveToOpponentKing(Move move) const
{
    // case black piece moved to white king:
    if (this->getPiece(move.start)->getColor() == BLACK && move.isEat && this->getPiece(move.eat)->getSymbol() == 'K')
    {
        return true;
    }

    // case white piece moved to black king:
    if (this->getPiece(move.start)->getColor() == WHITE && move.isEat && this->getPiece(move.eat)->getSymbol() == 'k')
    {
        return true;
    }
    return false;
}

bool Board::isKingCapture(Color playerOfTheKing) const
{   // foreach piece on the board:
    for (auto& row : board)
    {
        for (auto& piece : row)
        {
            // if the piece is not null and its opponent piece:
            if (piece != nullptr && piece->getColor() != playerOfTheKing)
            {
				vector<Move> legalMoves = piece->getAllLegalMoves();
                for (Move move : legalMoves)
                {
                    // return true if the move is to opponent king:
                    if (this->isMoveToOpponentKing(move))
						return true;
				}
			}
		}
	}
    return false;
}


vector<Move> Board::getAllLegalMoves(Color player) 
{
    vector<Move> allLegalMoves;
    for (auto& row : board)
    {
        for (auto& piece : row)
        {
            if (piece != nullptr && piece->getColor() == player) // the piece of the given player:
            {
                // store the all legal moves of the piece:
                vector<Move> legalMoves = piece->getAllLegalMoves();
                for (Move move : legalMoves) // foreach legal move of the piece:
                {
                    // copy the board with copy constructor:
                    Board boardCopy(*this);
                    // move the piece on the board copy:
                    boardCopy.movePiece(move);
                    // if the king
                    if (!boardCopy.isKingCapture(player))
                    {
						allLegalMoves.push_back(move);
					}
                }
            }
        }
    }
    return allLegalMoves;
}


void Board::movePiece(Move move)
{

    // check the turn of the player:
    if (this->turn != this->getPiece(move.start)->getColor())
    {
		cout << "It's not your turn!";
        return;
	}

    Piece* piece = this->getPiece(move.start);

    // move the piece on the board
    piece->move(move.end);

    // null the start location:
    this->board[move.start.getX()][move.start.getY()] = nullptr;

    // if the move is eat:
    if (move.isEat)
    {
		// delete the eat piece:
		delete this->board[move.eat.getX()][move.eat.getY()];
		// null the eat location:
		this->board[move.eat.getX()][move.eat.getY()] = nullptr;
	}


    // case pawn move 2 steps
    if (piece->getSymbol() == 'P' &&  move.end.getY() == 4)
    {
        this->can_en_passant = true;
        this->en_passant_location = Location(move.start.getX(), 5);
    }
    else if (piece->getSymbol() == 'p' && move.end.getY() == 3)
    {
		this->can_en_passant = true;
		this->en_passant_location = Location(move.start.getX(), 2);
	}
    else
    {
		this->can_en_passant = false;
		this->en_passant_location = Location(-1, -1);
	}

    // pawn promotion (to queen):
    if (piece->getSymbol() == 'P' && move.end.getY() == 0)
    {
		// delete the pawn:
		delete this->board[move.end.getX()][move.end.getY()];
		// create new queen:
		this->board[move.end.getX()][move.end.getY()] = new Queen(WHITE, move.end, this);
	}
    else if (piece->getSymbol() == 'p' && move.end.getY() == 7)
    {
		// delete the pawn:
		delete this->board[move.end.getX()][move.end.getY()];
		// create new queen:
		this->board[move.end.getX()][move.end.getY()] = new Queen(BLACK, move.end, this);
	}

    // update the board with the new location of the piece:
    this->board[move.end.getX()][move.end.getY()] =  piece;

    // change the turn:
    this->turn = (this->turn == WHITE) ? BLACK : WHITE;
}


// =============================================
//  methodes for adapting the board to the GUI:
//==============================================

// code 11: the source location is empty
bool Board::sourceLocationIsEmpty(Location sourceLocation) const
{
    if (this->board[sourceLocation.getX()][sourceLocation.getY()] == nullptr)
		return true;
}

// code 12: the source location is opponent piece
bool Board::sourceLocationIsOpponentPiece(Location sourceLocation, Color player) const
{
    if (this->board[sourceLocation.getX()][sourceLocation.getY()]->getColor() != player)
        return true;
}

// code 13: the destination location is player piece
bool Board::destinationLocationIsPlayerPiece(Location destinationLocation, Color player) const
{
    if (this->board[destinationLocation.getX()][destinationLocation.getY()]->getColor() == player)
		return true;
}

// code 21: the Move is illegal Because the Piece is not move like that
bool Board::MoveIsNotLegal(Move move) const
{
    // all moves of the piece:
    vector<Move> pieceMoves = this->board[move.start.getX()][move.start.getY()]->getAllLegalMoves();
    // foreach move of the piece:
    for (Move pieceMove : pieceMoves)
    {
		// if the move is legal:
		if (pieceMove.start == move.start && pieceMove.end == move.end)
			return false;
	}
    return true;
}

// code 31: the Move will cause checkmate
bool Board::MoveWillCauseCheckmate(Move move, Color player)
{
    // save all the moves of the piece and save all the board legal moves:
    // if the piece move is not in the board legal moves: return true
    // else: return false
    vector<Move> pieceMoves = this->board[move.start.getX()][move.start.getY()]->getAllLegalMoves();
    vector<Move> boardLegalMoves = this->getAllLegalMoves(player); // the board legal moves of the player
    for (Move pieceMove : pieceMoves)
    {
        if (pieceMove.start == move.start && pieceMove.end == move.end)
        {
            for (Move boardLegalMove : boardLegalMoves)
            {
				if (boardLegalMove.start == move.start && boardLegalMove.end == move.end)
					return false;
			}
			return true;
		}
	}
    return false;
}

// code 41: move is legal and cause check
bool Board::MoveIsLegalAndCauseCheck(Move move, Color player)
{
    vector<Move> boardLegalMoves = this->getAllLegalMoves(player); // the board legal moves of the player
    if (boardLegalMoves.size() == 0 && this->isKingCapture(player))
		return true;
    else 
        return false;
}

// code 42: move is legal and not cause check
bool Board::MoveIsLegalAndNotCauseCheck(Move move, Color player)
{
    vector<Move> boardLegalMoves = this->getAllLegalMoves(player); // the board legal moves of the player
	if (boardLegalMoves.size() != 0)
		return true;
	else 
		return false;

}





