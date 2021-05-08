#include <stdexcept>
#include <iostream>
#include <string>
#include "Viewer.h"
#include "GameManager.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Viewer::Viewer() {
	game_manager = nullptr;
}

Viewer::Viewer(GameManager* gm_from) {
	game_manager = gm_from;
}

Viewer::~Viewer() {

}

void Viewer::render_board() {
	cout << "render board" << endl;
	char board[8][8];

	for (int i = 0; i < 64; i++)board[i/8][i%8] = ' ';
	
	for (auto& team : game_manager->board.pieces) {
		for (auto& p : team.second) {
			int row = p.position.row - 1;
			int col = p.position.col - 1;
			switch (p.piece_type)
			{
			case PieceType::King:
				board[row][col] = 'K';
				break;
			case PieceType::Queen:
				board[row][col] = 'Q';
				break;
			case PieceType::Bishop:
				board[row][col] = 'B';
				break;
			case PieceType::Knight:
				board[row][col] = 'K';
				break;
			case PieceType::Rook:
				board[row][col] = 'R';
				break;
			case PieceType::Pawn:
				board[row][col] = 'P';
				break;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void Viewer::render_main() {
	string a;
	while (cin>>a)
	{

	}
}