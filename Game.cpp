#include "Game.hpp"

Game::Game( void ) : bSpeed(0), eSpeed(0), eSpeed2(2000),
			   direction(true), _start(true), _finish(false)
{
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
	this->newGame();
	this->player.setAbsCoordinates(Coordinates(this->_width / 2 - 1, this->_height - 2));
	this->displayAll();
	this->_start = false;
}

void	Game::display( Entitie const &src )
{
	for (unsigned int j = 0; j < src.getMaxCoordinates().getX(); j++) {
		for (unsigned int k = 0; k < src.getMaxCoordinates().getY(); k++) {
			mvprintw(src.getAbsCoordinates().getY() + k, src.getAbsCoordinates().getX() + j, "%c", src.getType());
		}
	}
}

void Game::newGame()
{
	int num = 0;

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 6; i++) {
			this->enemies[num].setAbsCoordinates(Coordinates(this->_width / 5 + i * (2 + 3 * this->_width / 30), this->_height / 5 + j * 3));
			this->enemies[num].setLiveStatus(true);
			num++;
		}
	}
	this->direction = true;
}

Game::~Game()
{
	endwin();
	return ;
}

Game & Game::operator=( Game const &rhs )
{
	if (this != &rhs)
	{
		this->bSpeed = rhs.bSpeed;
		this->eSpeed = rhs.eSpeed;
		this->eSpeed2 = rhs.eSpeed2;
		this->direction = rhs.direction;
		this->dur = rhs.dur;
		this->start = rhs.start;
		this->_start = rhs._start;
		this->_finish = rhs._finish;
		this->_width = rhs._width;
		this->_height = rhs._height;
		this->player = rhs.player;
		for (int currentEnemy = 0; currentEnemy < 12; currentEnemy++) {
			this->enemies[currentEnemy] = rhs.enemies[currentEnemy];
		}
		for (int currentBullet = 0; currentBullet < 42; currentBullet++) {
			this->enemies[currentBullet] = rhs.enemies[currentBullet];
		}
	}
	return *this;
}

bool	Game::checkIntersectionOfEntities( Entitie const & first, Entitie const & second )
{
	for (unsigned int firstY = 0; firstY < first.getMaxCoordinates().getY(); firstY++) {
		for (unsigned int firstX = 0; firstX < first.getMaxCoordinates().getX(); firstX++) {
			for (unsigned int secondY = 0; secondY < second.getMaxCoordinates().getY(); secondY++) {
				for (unsigned int secondX = 0; secondX < second.getMaxCoordinates().getX(); secondX++) {
					if (first.getAbsCoordinates().getX() + firstX == second.getAbsCoordinates().getX() + secondX
					&& first.getAbsCoordinates().getY() + firstY == second.getAbsCoordinates().getY() + secondY) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

void	Game::updatePlayerProperties( void )
{
	int currentEnemy = -1;
	while (++currentEnemy < 12) {
		if (this->enemies[currentEnemy].alive()) {
			if (Game::checkIntersectionOfEntities(this->enemies[currentEnemy], this->player)) {
				this->_finish = true;
				break ;
			}
		}
	}
}

void	Game::updateGameEntitiesProperties( void )
{
	Game::updatePlayerProperties();
	for (int currentEnemy = 0; currentEnemy < 12; currentEnemy++) {
		if (this->enemies[currentEnemy].alive()) {
			for (int currentBullet = 0; currentBullet < 42; currentBullet++) {
				if (this->bullets[currentEnemy].alive()) {
					if (Game::checkIntersectionOfEntities(enemies[currentEnemy], bullets[currentBullet])) {
						this->enemies[currentEnemy].setLiveStatus(false);
						this->bullets[currentBullet].setLiveStatus(false);
					}
				}
			}
		}
	}
}


