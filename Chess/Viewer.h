#pragma once

class GameManager;

class Viewer
{
	GameManager * game_manager;

public:
	
	Viewer(); // not allow
	Viewer(GameManager*);
	~Viewer();

	void render_board();
	void render_main();
};

