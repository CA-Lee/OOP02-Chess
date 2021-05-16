#include <stdexcept>
#include <iostream>
#include <string>
#include "Viewer.h"
#include "GameManager.h"
#include "../rang-master/include/rang.hpp"
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

Viewer::Viewer() {
	game_manager = nullptr;
}

Viewer::Viewer(GameManager* gm_from) {
	game_manager = gm_from;
}

Viewer::~Viewer() {

}

void Viewer::render_gf() {
	clear();

	render_board();
	render_game_status();
}

void Viewer::render_sf() {
	cout << "Press Enter to start.";
	string a;
	getline(cin ,a);
	game_manager->start_game(GameMode::p2p);
}

void Viewer::render_board() {
	auto dark_bg = rang::bg::blue;
	auto bright_bg = rang::bg::yellow;

	cout << rang::style::reversed << " ";
	for (char i = 'a'; i <= 'h'; i++)cout << "  " << i << "  ";
	cout << " " << rang::style::reset << endl;

	for (int i = 7; i >= 0; i--) {
		reset();
		cout << rang::style::reversed << " ";
		reset();

		for (int j = 0; j < 8; j++) {
			(i & 1) == (j & 1) ?
				cout << dark_bg :
				cout << bright_bg;
			cout << "     ";
		}
		reset();
		cout << rang::style::reversed << " ";
		reset();

		cout << endl;

		reset();
		cout << rang::style::reversed << i + 1;
		reset();
		for (int j = 0; j < 8; j++) {
			(i & 1) == (j & 1) ?
				cout << dark_bg :
				cout << bright_bg;
			Piece* piece = game_manager->board.at(Position(i + 1, j + 1));
			if (piece != nullptr) {
				cout << "  ";

				reset();
				if (piece->team == Team::White) cout << rang::style::reversed;
				switch (piece->piece_type)
				{
				case PieceType::King:
					cout << 'K';
					break;
				case PieceType::Queen:
					cout << 'Q';
					break;
				case PieceType::Bishop:
					cout << 'B';
					break;
				case PieceType::Knight:
					cout << 'N';
					break;
				case PieceType::Rook:
					cout << 'R';
					break;
				case PieceType::Pawn:
					cout << 'P';
					break;
				}
				reset();
				(i & 1) == (j & 1) ?
					cout << dark_bg :
					cout << bright_bg;
				cout << "  ";
			}
			else
			{
				cout << "     ";
			}
		}

		reset();
		cout << rang::style::reversed << i + 1;
		reset();

		cout << endl;

		reset();
		cout << rang::style::reversed << " ";
		reset();
		for (int j = 0; j < 8; j++) {
			(i & 1) == (j & 1) ?
				cout << dark_bg :
				cout << bright_bg;
			cout << "     ";
		}
		reset();
		cout << rang::style::reversed << " ";
		reset();

		cout << endl;
	}

	cout << rang::style::reversed << " ";
	for (char i = 'a'; i <= 'h'; i++)cout << "  " << i << "  ";
	cout << " " << rang::style::reset << endl;


	reset();
}

void Viewer::render_game_status() {
	cout << "It's " 
		<< (game_manager->stage == Team::White ? "white" : "black")
		<< "'s turn" << endl;
}

Move Viewer::get_move() {
	while (true) {
		cout << "Enter a move (eg. e3 b3)" << endl;
		string from, to;
		cin >> from >> to;
		if (from.size() != 2 || to.size() != 2 ||
			!(from[0] >= 'a' && from[0] <= 'h') ||
			!(from[1] >= '1' && from[1] <= '8') ||
			!(to[0] >= 'a' && to[0] <= 'h') ||
			!(to[1] >= '1' && to[1] <= '8')
			) {
			cout << "Invalid input." << endl;
			continue;
		}

		Move m(
			Position(from[1] - '0', from[0] - 'a' + 1),
			Position(to[1] - '0', to[0] - 'a' + 1)
		);

		if (game_manager->board.validate_move(m))return m;
		else cout << "Invalid move." << endl;
	} 
}


void Viewer::clear() {
	cout << "\x1B[2J\x1B[H";
}

void Viewer::reset() {
	cout << rang::style::reset << rang::fg::reset << rang::bg::reset;
}