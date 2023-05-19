// Chess 
// #include "Chess.h"



// int main()
// {
// 	/* */
// 	string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
// //	string board = "##########K###############################R#############r#r#####";
// 	Chess a(board);
// 	int codeResponse = 0;
// 	string res = a.getInput(); 
// 	while (res != "exit")
// 	{
// 		/* 
// 		codeResponse value : 
// 		Illegal movements : 
// 		11 - there is not piece at the source  
// 		12 - the piece in the source is piece of your opponent
// 		13 - there one of your pieces at the destination 
// 		21 - illegal movement of that piece 
// 		31 - this movement will cause you checkmate

// 		legal movements : 
// 		41 - the last movement was legal and cause check 
// 		42 - the last movement was legal, next turn 
// 		*/

// 		/**/
// 		{ // put your code here instead that code
// 			cout << "code response >> ";
// 			cin >> codeResponse;
// 		}
// 		/**/

// 		a.setCodeResponse(codeResponse);
// 		res = a.getInput(); 
// 	}

// 	cout << endl << "Exiting " << endl; 
// 	return 0;
// }


// ==================
// Temp Main Class:
// ==================

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

#include "Board.h"
#include "Piece.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"


int main()
{
	Board board;
	// ======================
	//	test all the pieces:
	// ======================
	/*
	// White Pawn
	board.testBoard("########|########|##p#p###|###P####|##p#p###|########|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));

	// White Pawn enpassant
	board.testBoard("########|########|##p#####|###Pp###|########|########|########|########");
	board.setEnPassantLocation(Location(4, 2));
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));
	board.setEnPassantFalse();
	cout << "====================" << endl << endl;

	// White king
	board.testBoard("########|########|##p#####|##pK###|###pp###|########|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));
	cout << "====================" << endl << endl;

	// white bishop
	board.testBoard("########|########|##p#####|##pB###|###pp###|########|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));
	cout << "====================" << endl << endl;

	// white knight
	board.testBoard("########|########|##p#####|##pN###|###pp###|pppppppp|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));
	cout << "====================" << endl << endl;

	// white rook
	board.testBoard("########|########|##p#####|##pR###|###pp###|########|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));

	// white queen
	board.testBoard("########|########|##p#####|##pQ###|###pp###|########|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));

	// black pawn
	board.testBoard("########|########|##P#P###|###p####|##P#P###|########|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));

	// black pawn enpassant
	board.testBoard("########|########|########|########|###pP###|########|########|########");
	board.setEnPassantLocation(Location(4, 5));
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 4));
	board.setEnPassantFalse();
	cout << "====================" << endl << endl;

	// black king
	board.testBoard("########|########|########|##PkP###|##PP####|########|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));
	cout << "====================" << endl << endl;

	// black bishop
	board.testBoard("########|########|########|##Pb####|##PP####|########|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));
	cout << "====================" << endl << endl;

	// black knight
	board.testBoard("########|########|########|##Pn####|##PP####|########|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));
	cout << "====================" << endl << endl;

	// black rook
	board.testBoard("########|########|########|##Pr####|##PP####|########|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));
	cout << "====================" << endl << endl;

	// black queen
	board.testBoard("########|########|########|##Pq####|##PP####|########|########|########");
	board.PrintBoard();
	board.printAllPieceLegalMoves(Location(3, 3));
	cout << "====================" << endl << endl;
	cout << "====================" << endl << endl;

	// chack for king capture
	board.testBoard("########|########|########|##pKp###|########|########|########|########");
	board.PrintBoard();
	cout << endl << board.isKingCapture(WHITE) << endl;

	// chack for king capture
	board.testBoard("########|########|########|##qK###|########|########|########|########");
	board.PrintBoard();
	cout << endl << board.isKingCapture(WHITE) << endl;

	// chack for king capture
	board.testBoard("########|########|########|##PkP###|########|########|########|########");
	board.PrintBoard();
	cout << endl << board.isKingCapture(BLACK) << endl;

	// chack for king capture
	board.testBoard("########|########|########|##Qk###|########|########|########|########");
	board.PrintBoard();
	cout << endl << board.isKingCapture(BLACK) << endl;
	*/
	// chack the All legal moves:
	board.testBoard("########|########|########|###K#Pr#|########|########|########|########");
	cout << "Board with white king and white pawn that pin the king from black rook" << endl;
	board.PrintBoard();
	cout << " all the legal moves for the black player: " << endl;
	vector<Move> allLegalMoves = board.getAllLegalMoves(BLACK);
	for (int i = 0; i < allLegalMoves.size(); i++)
	{
		cout << allLegalMoves[i] << endl;
	}
	cout << endl;
	cout << " all the legal moves for the white player: " << endl;
	allLegalMoves = board.getAllLegalMoves(WHITE);
	for (int i = 0; i < allLegalMoves.size(); i++)
	{
		cout << allLegalMoves[i] << endl;
	}
	cout << endl;

	if (board.isKingCapture(WHITE))
		cout << "The white king is in check" << endl << endl << endl;
	else
		cout << "The white king is not in check" <<endl<< "========================" << endl << endl;

	// copy the board:
	Board board2 = board;

	

	cout << endl << endl;
	cout << "After moving the piece: " << endl;
	board.movePiece(Move(Location(5, 3), Location(5, 2)));
	board.PrintBoard();

	cout << endl;
	cout << " all the legal moves for the black player: " << endl;
	allLegalMoves = board.getAllLegalMoves(BLACK);
	for (int i = 0; i < allLegalMoves.size(); i++)
	{
		cout << allLegalMoves[i] << endl;
	}
	allLegalMoves = board.getAllLegalMoves(WHITE);
	cout << endl;
	cout << " all the legal moves for the white player: " << endl;
	for (int i = 0; i < allLegalMoves.size(); i++)
	{
		cout << allLegalMoves[i] << endl;
	}
	// print is the white king in check
	cout << endl;
	if (board.isKingCapture(WHITE))
		cout << "The white king is in check" << endl;
	else
		cout << "The white king is not in check" << endl;


	cout << endl << endl;

	// print the board2:
	board2.PrintBoard();
	cout << endl;
	cout << " all the legal moves for the black player: " << endl;
	allLegalMoves = board2.getAllLegalMoves(BLACK);
	for (int i = 0; i < allLegalMoves.size(); i++)
	{
		cout << allLegalMoves[i] << endl;
	}
	allLegalMoves = board2.getAllLegalMoves(WHITE);
	cout << endl;
	cout << " all the legal moves for the white player: " << endl;
	for (int i = 0; i < allLegalMoves.size(); i++)
	{
		cout << allLegalMoves[i] << endl;
	}
	// print is the white king in check
	cout << endl;
	if (board2.isKingCapture(WHITE))
		cout << "The white king is in check" << endl;
	else
		cout << "The white king is not in check" << endl;

	


	return 0;
}

