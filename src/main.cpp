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
	cout << "Hello World!" << endl;
	Board board;
	//board.PrintAllPieces();
	board.PrintBoard();
	return 0;
}

