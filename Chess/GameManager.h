#pragma once
#include <vector>
#include "Player.h"
#include "Board.h"
#include "Viewer.h"
#include "GameSetting.h"

using std::vector;

class GameManager
{
	
	vector<Player*> players;
	int current_player = 0;
	Board board;
	Viewer viewer;
	GameSetting setting;

public:
	GameManager();
	~GameManager();
	void start();
};

