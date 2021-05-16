#include "GameManager.h"

GameManager::GameManager() {
	players = map<Team, Player*>();
	viewer = Viewer(this);
	board = Board(this);
}

GameManager::~GameManager() {
	delete players[Team::White];
	delete players[Team::Black];
}

void GameManager::start() {
	viewer.render_sf();
}

void GameManager::start_game(GameMode mode) {

	if (mode == GameMode::p2p) {
		players[Team::White] = new HumanPlayer(this, "White");
		players[Team::Black] = new HumanPlayer(this, "Black");
	}

	stage = Team::White;
	while (1) {
		viewer.render_gf();
		
		Move move = players[stage]->OnMove();
		board.move_piece(move);

		// check promote
		if (board.at(move.to)->piece_type == PieceType::Pawn &&
			board.at(move.to)->position.row == (board.at(move.to)->team == Team::White ? 8 : 1)
			) {
			PieceType promote_to = players[stage]->OnPromote();
			board.at(move.to)->piece_type = promote_to;
			viewer.render_gf();
		}

		// check situation

		stage = (stage == Team::White ? Team::Black : Team::White);
	}
}

void GameManager::game_over() {
	// load end frame
	// show game result
}