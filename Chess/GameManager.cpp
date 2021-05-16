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
		players[Team::White] = new HumanPlayer(this, "Player1");
		players[Team::Black] = new HumanPlayer(this, "Player2");
	}

	stage = Team::White;
	while (1) {
		viewer.render_gf();
		
		board.move_piece(players[stage]->OnMove());

		// check situation

		stage = (stage == Team::White ? Team::Black : Team::White);
	}
}

void GameManager::game_over() {
	// load end frame
	// show game result
}