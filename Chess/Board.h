#pragma once
#include <map>
#include <vector>
#include "Piece.h"

using std::map;
using std::vector;

struct Move
{
	Position from;
	Position to;

	Move(Position f, Position t) {
		from = f;
		to = t;
	}

};

class Board
{
public:
	map<Team, vector< Piece>> pieces;

	Board();
	
	Piece* at(Position);
	void kill(Piece*);

	bool validate_move(Move);
	void move_piece(Move);
};

