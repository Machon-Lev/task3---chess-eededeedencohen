// Chess 
#include "Chess.h"
#include "Board.h"



int main()
{
	/* */   
	string board = "#######k########################################PPRPPPPP#q##KBNR";
	//board = "################################################################";
	Board backstageBoard;
	
	backstageBoard.testBoard("#######k########################################PPRPPPPP#q##KBNR");
//	string board = "##########K###############################R#############r#r#####";
	Chess a(board);
	int codeResponse = 0;
	string res = a.getInput(); 
	int ySource = res[0] - 'a';
	int xSource = res[1] - '1';
	int yDest = res[2] - 'a';
	int xDest = res[3] - '1';
	Move turnMove;
	turnMove.start = Location(xSource, ySource);
	turnMove.end = Location(xDest, yDest);
	int code = backstageBoard.getCodeOfMoving(turnMove);
	cout << "code = " << code << endl;

	while (res != "exit")
	{
		backstageBoard.PrintBoard();
		/* 
		codeResponse value : 
		Illegal movements : 
		11 - there is not piece at the source  
		12 - the piece in the source is piece of your opponent
		13 - there one of your pieces at the destination 
		21 - illegal movement of that piece 
		31 - this movement will cause you checkmate

		legal movements : 
		41 - the last movement was legal and cause check 
		42 - the last movement was legal, next turn 
		*/
		
		//codeResponse = b.getCodeOfMoving(b.convertStringMoveToMove(res));

		/**/
		{ // put your code here instead that code
			cout << "code response >> " << code;
			//cin >> codeResponse;			
		}
		/**/
		a.setCodeResponse(code);
		res = a.getInput(); 

		// conver the input to move 
		int ySource = res[0] - 'a';
		cout << "ySource = " << ySource << endl;
		int xSource = res[1] - '1';
		cout << "xSource = " << xSource << endl;
		int yDest = res[2] - 'a';
		cout << "yDest = " << yDest << endl;
		int xDest = res[3] - '1';
		cout << "xDest = " << xDest << endl;
		backstageBoard.PrintAllPieces();
		backstageBoard.getAllLegalMoves(backstageBoard.getTurn());
		turnMove.start = Location(xSource, ySource);
		turnMove.end = Location(xDest, yDest);

		// check the code of the movement
		code = backstageBoard.getCodeOfMoving(turnMove);
		cout << "code = " << code << endl;
	}

	cout << endl << "Exiting " << endl; 
	return 0;
}


// ==================
// Temp Main Class:
// ==================

// #include <iostream>
// #include <string>
// using std::cout;
// using std::cin;
// using std::endl;

// #include "Board.h"
// #include "Piece.h"
// #include "Bishop.h"
// #include "King.h"
// #include "Knight.h"
// #include "Pawn.h"
// #include "Queen.h"
// #include "Rook.h"


// int main()
// {
// 	Board board;
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
	// board.testBoard("########|########|########|###K#Pr#|########|########|########|########");
	// cout << "Board with white king and white pawn that pin the king from black rook" << endl;
	// board.PrintBoard();
	// cout << " all the legal moves for the black player: " << endl;
	// vector<Move> allLegalMoves = board.getAllLegalMoves(BLACK);
	// for (int i = 0; i < allLegalMoves.size(); i++)
	// {
	// 	cout << allLegalMoves[i] << endl;
	// }
	// cout << endl;
	// cout << " all the legal moves for the white player: " << endl;
	// allLegalMoves = board.getAllLegalMoves(WHITE);
	// for (int i = 0; i < allLegalMoves.size(); i++)
	// {
	// 	cout << allLegalMoves[i] << endl;
	// }
	// cout << endl;

	// if (board.isKingCapture(WHITE))
	// 	cout << "The white king is in check" << endl << endl << endl;
	// else
	// 	cout << "The white king is not in check" <<endl<< "========================" << endl << endl;

	// // copy the board:
	// Board board2 = board;

	

	// cout << endl << endl;
	// cout << "After moving the piece: " << endl;
	// board.movePiece(Move(Location(5, 3), Location(5, 2)));
	// board.PrintBoard();

	// cout << endl;
	// cout << " all the legal moves for the black player: " << endl;
	// allLegalMoves = board.getAllLegalMoves(BLACK);
	// for (int i = 0; i < allLegalMoves.size(); i++)
	// {
	// 	cout << allLegalMoves[i] << endl;
	// }
	// allLegalMoves = board.getAllLegalMoves(WHITE);
	// cout << endl;
	// cout << " all the legal moves for the white player: " << endl;
	// for (int i = 0; i < allLegalMoves.size(); i++)
	// {
	// 	cout << allLegalMoves[i] << endl;
	// }
	// // print is the white king in check
	// cout << endl;
	// if (board.isKingCapture(WHITE))
	// 	cout << "The white king is in check" << endl;
	// else
	// 	cout << "The white king is not in check" << endl;


	// cout << endl << endl;

	// // print the board2:
	// board2.PrintBoard();
	// cout << endl;
	// cout << " all the legal moves for the black player: " << endl;
	// allLegalMoves = board2.getAllLegalMoves(BLACK);
	// for (int i = 0; i < allLegalMoves.size(); i++)
	// {
	// 	cout << allLegalMoves[i] << endl;
	// }
	// allLegalMoves = board2.getAllLegalMoves(WHITE);
	// cout << endl;
	// cout << " all the legal moves for the white player: " << endl;
	// for (int i = 0; i < allLegalMoves.size(); i++)
	// {
	// 	cout << allLegalMoves[i] << endl;
	// }
	// // print is the white king in check
	// cout << endl;
	// if (board2.isKingCapture(WHITE))
	// 	cout << "The white king is in check" << endl;
	// else
	// 	cout << "The white king is not in check" << endl;




	//========================
	// test the board class:
	//========================
	// board.PrintBoard();
	// Location from(-1, -1);
	// Location to(-1, -1);
	// int xFrom=0, yFrom=0, xTo=0, yTo=0;
	// // while loop for the game until press -1 -1 -1 -1

	// while (true)
	// {
	// 	vector<Move> allLegalMoves = board.getAllLegalMoves(board.getTurn());
	// 	// print all the legal moves
	// 	cout << "All the legal moves for the " << board.getTurn() << " player:" << endl;
	// 	for (int i = 0; i < allLegalMoves.size(); i++)
	// 	{
	// 		cout << allLegalMoves[i] << endl;
	// 	}
	// 	cout << endl;

	// 	cin >> xFrom >> yFrom >> xTo >> yTo;
	// 	if (xFrom == -1 && yFrom == -1 && xTo == -1 && yTo == -1)
	// 		break;
	// 	from = Location(xFrom, yFrom);
	// 	to = Location(xTo, yTo);

	// 	// validate if is legal move
	// 	bool isLegalMove = false;
	// 	int indexOfLegalMove = -1;
	// 	for (int i = 0; i < allLegalMoves.size(); i++)
	// 	{
	// 		if (allLegalMoves[i].start == from && allLegalMoves[i].end == to)
	// 		{
	// 			isLegalMove = true;
	// 			indexOfLegalMove = i;
	// 			break;
	// 		}
	// 	}
	// 	if (!isLegalMove)
	// 	{
	// 		system("cls");
	// 		board.PrintBoard();
	// 		cout << "Illegal move" << endl;
	// 		continue;
	// 	}

	// 	// move the piece
	// 	board.movePiece(allLegalMoves[indexOfLegalMove]);

	// 	// clear the screen
	// 	system("cls");

	// 	// print the board
	// 	board.PrintBoard();
	// }

//	return 0;
//}

