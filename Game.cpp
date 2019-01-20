#include "Game.hpp"

Game::Game() : bSpeed(0) {
	unsigned int max_x;
	unsigned int max_y;

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
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
	this->player.setAbsCoordinates(Coordinates(max_x / 2 - 1, max_y - 1));
	this->displayAll();
}

void	Game::display( Entitie const &src ) {
	for (unsigned int j = 0; j < src.getMaxCoordinates().getX(); j++) {
		for (unsigned int k = 0; k < src.getMaxCoordinates().getY(); k++) {
			mvprintw(src.getAbsCoordinates().getY() + k, src.getAbsCoordinates().getX() + j, "%c", src.getType());
		}
	}
}

Game::~Game()
{
	endwin();
	return ;
}

void	Game::updatePlayerProperties( bool side )
{
	int currentEnemy = -1;
	while (++currentEnemy < 12)
	{
		if (this->enemies[currentEnemy].alive()
		&& (this->enemies[currentEnemy].getAbsCoordinates().getX() == this->player.getAbsCoordinates().getX()
		|| this->enemies[currentEnemy].getAbsCoordinates().getY() == this->player.getAbsCoordinates().getY()))
		{
			this->_finish;
			break ;
		}
	}
}

void	Game::updateGameEntitiesProperties( void )
{
	for (int currentEnemy = 0; currentEnemy < 42; currentEnemy++)
	{
		if (this->enemies[currentEnemy].alive())
		{
			for (int currentBullet = 0; currentBullet < 42; currentBullet++)
			{
				if (this->enemies[currentEnemy].getAbsCoordinates().getX() == this->bullets[currentBullet].getAbsCoordinates().getX()
				|| this->enemies[currentEnemy].getAbsCoordinates().getY() == this->bullets[currentBullet].getAbsCoordinates().getY())
				{
					this->enemies[currentEnemy].setLiveStatus(false);
					this->bullets[currentBullet].setLiveStatus(false);
				}
			}
		}
	}
}
