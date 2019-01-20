#include "Game.hpp"

Game::Game() : bSpeed(0), _start(true), eSpeed(0), direction(true), _finish(false) {
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
	this->_width = max_x;
	this->_height = max_y;
	int num = 0;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 6; i++) {
			this->enemies[num].setAbsCoordinates(Coordinates(max_x / 5 + i*(2 + 3*max_x/30), max_y / 5 + j*3));
			num++;
		}
	}
	this->player.setAbsCoordinates(Coordinates(max_x / 2 - 1, max_y - 1));
	this->displayAll();
	this->_start = false;
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

void	Game::updatePlayerProperties( void )
{
	int currentEnemy = -1;
	while (++currentEnemy < 12)
	{
		if (Game::checkIntersectionOfEntities(this->enemies[currentEnemy], this->player))
		{
			this->_finish = true;
			break ;
		}
	}
}

bool	Game::checkIntersectionOfEntities( Entitie const & first, Entitie const & second )
{
	Coordinates firstCoordinates = first.getAbsCoordinates();
	Coordinates secondCoordinates = second.getAbsCoordinates();
	while (firstCoordinates.getY() + first.getMaxCoordinates().getY() < first.getMaxCoordinates().getY())
	{
		firstCoordinates.setX(firstCoordinates.getX());
		while (firstCoordinates.getX() + first.getMaxCoordinates().getX() < first.getMaxCoordinates().getX())
		{
			secondCoordinates.setY(secondCoordinates.getY());
			while (secondCoordinates.getY() + second.getMaxCoordinates().getY() < second.getMaxCoordinates().getY())
			{
				secondCoordinates.setX(secondCoordinates.getX());
				while (secondCoordinates.getX() + second.getMaxCoordinates().getX() < second.getMaxCoordinates().getX())
				{
					if (firstCoordinates.getY() == secondCoordinates.getX()
					&& firstCoordinates.getY() == secondCoordinates.getY())
						return true;
					secondCoordinates.setX(secondCoordinates.getX() + 1);
				}
				secondCoordinates.setY(secondCoordinates.getY() + 1);
			}
			secondCoordinates.setX(secondCoordinates.getX() + 1);
		}
		secondCoordinates.setY(secondCoordinates.getY() + 1);
	}
	return false;
}

void	Game::updateGameEntitiesProperties( void )
{
	for (int currentEnemy = 0; currentEnemy < 42; currentEnemy++)
	{
		if (!this->enemies[currentEnemy].alive())
		{
			for (int currentBullet = 0; currentBullet < 42; currentBullet++)
			{
				if (this->bullets[currentEnemy].alive())
				{
					if (Game::checkIntersectionOfEntities(enemies[currentEnemy], bullets[currentBullet]))
					{
						this->enemies[currentEnemy].setLiveStatus(false);
						this->bullets[currentBullet].setLiveStatus(false);
					}
				}
			}
		}
	}
}
