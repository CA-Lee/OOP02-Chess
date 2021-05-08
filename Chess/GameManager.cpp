#include "GameManager.h"

void GameManager::start() {
	viewer.render_board();
}

GameManager::GameManager() {
	players = vector<Player*>(2);
	viewer = Viewer(this);
	board = Board();
}

GameManager::~GameManager() {
	delete players[0];
	delete players[1];
}