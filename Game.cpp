#include "Game.hpp"

Game::Game() {
	unsigned int max_x;
	unsigned int max_y;

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr,TRUE);
	refresh();
	getmaxyx(stdscr, max_y, max_x);
	int num = 0;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 6; i++) {
			this->enemies[num].setAbsCoordinates(Coordinates(max_x / 5 + i*(2 + 3*max_x/30), max_y / 5 + j*3));
			num++;
		}
	}
	for (int i = 0; i < 12; i++) {
		this->display(this->enemies[i]);
	}
	this->player.setAbsCoordinates(Coordinates(max_x / 2 - 1, max_y - 1));
	this->display(this->player);
	refresh();
}

void Game::display(Entitie const &src) {
	for (unsigned int j = 0; j < src.getMaxCoordinates().getX(); j++) {
		for (unsigned int k = 0; k < src.getMaxCoordinates().getY(); k++) {
			mvprintw(src.getAbsCoordinates().getY()+k,src.getAbsCoordinates().getX()+j, "%c", src.getType());
		}
	}
}

Game::~Game() {
	endwin();
	return ;
}


//void	Game::updateGameEntities( )
//{
//	for (int currentEnemy = 0; currentEnemy < 12; currentEnemy++)
//	{
//		if (game.enemies[currentEnemy].alive())
//		{
//			game.enemies[currentEnemy].getAbsCoordinates().setX(game.enemies[currentEnemy].getAbsCoordinates().getX() + 2);
//			// game.enemies[currentEnemy].getAbsCoordinates().setY(game.enemies[currentEnemy].getAbsCoordinates().getY() + 2);
//		}
//	}
//}