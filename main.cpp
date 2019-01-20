#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Game.hpp"

#include "iostream"

void Game::updatePlayerPos(int c) {
	if (c == 260) {
		this->player.setAbsCoordinates(Coordinates(this->player.getAbsCoordinates().getX()-1, this->player.getAbsCoordinates().getY()));
		if (this->player.getAbsCoordinates().getX() < 1)
			this->player.setAbsCoordinates(Coordinates(1, this->player.getAbsCoordinates().getY()));
	}
	else if (c == 261) {
		this->player.setAbsCoordinates(Coordinates(this->player.getAbsCoordinates().getX()+1, this->player.getAbsCoordinates().getY()));
		if (this->player.getAbsCoordinates().getX() > this->_width-4)
			this->player.setAbsCoordinates(Coordinates(this->_width-4, this->player.getAbsCoordinates().getY()));
	}

}

//Game::Game() : bSpeed(0) {
//	unsigned int max_x;
//	unsigned int max_y;
//
//	initscr();
//	cbreak();
//	noecho();
//	curs_set(0);
//	keypad(stdscr, TRUE);
//	nodelay(stdscr,TRUE);
//	refresh();
//	getmaxyx(stdscr, max_y, max_x);
//	int num = 0;
//	for (int j = 0; j < 2; j++) {
//		for (int i = 0; i < 6; i++) {
//			this->enemies[num].setAbsCoordinates(Coordinates(max_x / 5 + i*(2 + 3*max_x/30), max_y / 5 + j*3));
//			num++;
//		}
//	}
//	this->player.setAbsCoordinates(Coordinates(max_x / 2 - 1, max_y - 1));
//	this->displayAll();
//	refresh();
//}

void Game::displayAll() {
	clear();
	for (int i = 0; i < 12; i++) {
		if (this->enemies[i].alive())
			this->display(this->enemies[i]);
	}
	for (int i = 0; i < 42; i++) {
		if (this->bullets[i].alive())
			this->display(this->bullets[i]);
	}
	this->display(this->player);
	if (this->_start)
		mvprintw(1, this->_width/2 - 8, "PRESS ENTER TO START");
	else
		mvprintw(1, this->_width/2 - 8, "PRESS ESCAPE TO EXIT");
	refresh();
}


void Game::shoot() {
	for (int i = 0; i < 42; i++) {
		if (this->bullets[i].alive() == false) {
			this->bullets[i].setLiveStatus(true);
			this->bullets[i].setAbsCoordinates(Coordinates(this->player.getAbsCoordinates().getX()+1, this->player.getAbsCoordinates().getY()-1));
			return ;
		}
	}
}

void	Game::updateGameEntitiesB( )
{
	this->bSpeed++;
	if (this->bSpeed == 200)
	{
		this->bSpeed = 0;
		for (int i = 0; i < 42; i++)
		{
			if (this->bullets[i].alive())
			{
				this->bullets[i].setAbsCoordinates(Coordinates(this->bullets[i].getAbsCoordinates().getX(),
															   this->bullets[i].getAbsCoordinates().getY() - 1));
			}
		}
	}
//	this->eSpeed++;
//	if (this->eSpeed == 1000) {
//		if (direction) {
//			for (int i = 0; i < 12; i++) {
//				this->bullets[i].setAbsCoordinates(Coordinates(this->bullets[i].getAbsCoordinates().getX(),
//															   this->bullets[i].getAbsCoordinates().getY() - 1));
//			}
//		}
//	}

}

int main( void )
{
	Game game;
	int c;

	while ((c=getch()) != 10) {
		if (c == 27)
			return 0;
		else
			continue;
	}
	while ((c=getch()) != 27) {
		if (c == 32)
			game.shoot();
		else if (c == 260 || c == 261)
			game.updatePlayerPos(c);
		refresh();
		game.updateGameEntitiesProperties();
		game.updateGameEntitiesB();
		game.displayAll();
	}
	refresh();
    return 0;
}
