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
	Game(Game const &src);
	~Game();

//		Game &operator=(Game const &rhs);

	void 	display( Entitie const &src );
	
	void 	updateGameEntitiesProperties( void );
	void	updatePlayerProperties( void);

	void 	updateGameEntitiesB( void );

	void	shoot();
	void	updatePlayerPos(int c);
	void	displayAll();
	void	checkEnemies();
	void	newGame();

private:
	int				bSpeed;
	int				eSpeed;
	int				eSpeed2;
	bool			direction;

	bool			_start;
	bool			_finish;

	unsigned int	_width;
	unsigned int	_height;

	Player			player;
	Enemy			enemies[12];
	Bullet			bullets[42];

};

#endif
