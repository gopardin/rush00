#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"


class Game
{
	public:
		Game();
//		Game(Game const &src);
		~Game();

//		Game &operator=(Game const &rhs);

		void 	display(Entitie const &src);
		void 	updateGameEntities();

	private:
		bool 	_start;
		Player	player;
		Enemy	enemies[12];
		Bullet	bullets[42];
};



#endif
