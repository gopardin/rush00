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

void Game::displayAll() {
	clear();
	if (this->_finish)
		exit(0);
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
	this->dur = ( std::clock() - this->start ) / (double) CLOCKS_PER_SEC;
	mvprintw(1, this->_width - 10, "%f", this->dur);
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
	this->eSpeed++;
	if (this->eSpeed >= this->eSpeed2) {
		if (direction) {
			if (this->enemies[11].getAbsCoordinates().getX() > this->_width - this->_width / 13) {
				for (int i = 0; i < 12; i++)
					this->enemies[i].setAbsCoordinates(Coordinates(this->enemies[i].getAbsCoordinates().getX(),
																   this->enemies[i].getAbsCoordinates().getY() + 1));
				direction = !direction;
			}
			else {
				for (int i = 0; i < 12; i++)
					this->enemies[i].setAbsCoordinates(
							Coordinates(this->enemies[i].getAbsCoordinates().getX() + this->_width / 30,
										this->enemies[i].getAbsCoordinates().getY()));
			}
		}
		else {
			if (this->enemies[0].getAbsCoordinates().getX() < this->_width / 13) {
				for (int i = 0; i < 12; i++)
					this->enemies[i].setAbsCoordinates(Coordinates(this->enemies[i].getAbsCoordinates().getX(),
																   this->enemies[i].getAbsCoordinates().getY() + 1));
				direction = !direction;
			}
			else {
				for (int i = 0; i < 12; i++)
					this->enemies[i].setAbsCoordinates(
							Coordinates(this->enemies[i].getAbsCoordinates().getX() - this->_width / 30,
										this->enemies[i].getAbsCoordinates().getY()));
			}
		}
		this->eSpeed = 0;
	}

}

void Game::checkEnemies() {
	for (int i = 0; i < 12; i++) {
		if (this->enemies[i].alive()) {
			if (this->enemies[0].getAbsCoordinates().getY() < this->_height)
				return ;
		}
	}
	this->newGame();
	for (int i = 0; i < 12; i++) {
		if (this->enemies[i].getMaxCoordinates().getY() == 1)
			this->enemies[i].setMaxCoordinates(Coordinates(2, 2));
		else
			this->enemies[i].setMaxCoordinates(Coordinates(1, 1));
	}
	this->eSpeed2 -= 300;
	if (this->eSpeed2 < 0)
		this->eSpeed2 = 100;
}

void Game::setStart(std::clock_t start) {
	this->start=start;
}

int main( void )
{
	Game game;
	int c;
	double duration;

	while ((c=getch()) != 10) {
		if (c == 27)
			return 0;
		else
			continue;
	}
	std::clock_t start = std::clock();
	game.setStart(start);
	while ((c=getch()) != 27) {
		if (c == 32)
			game.shoot();
		else if (c == 260 || c == 261)
			game.updatePlayerPos(c);
		game.updatePlayerProperties();
		game.updateGameEntitiesProperties();
		game.displayAll();
		game.updateGameEntitiesB();
		game.checkEnemies();
	}
	refresh();
    return 0;
}
