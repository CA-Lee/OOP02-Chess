#include "GameManager.h"

void GameManager::start() {

}

GameManager::GameManager() {
	players = vector<Player*>(2);
}

GameManager::~GameManager() {
	delete players[0];
	delete players[1];
}