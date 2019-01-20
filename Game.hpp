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
	Game( void );
	Game(Game const &src);
	~Game( void );

	Game &	operator=( Game const &rhs );

	void 	display( Entitie const &src );
	
	void 	updateGameEntitiesProperties( void );
	void	updatePlayerProperties( void );

	void 	updateGameEntitiesB( void );
	bool	checkIntersectionOfEntities( Entitie const & first, Entitie const & second );

	void	shoot( void );
	void	updatePlayerPos(int c);
	void	displayAll( void );
	void	checkEnemies( void );
	void	newGame( void );
	void	setStart( std::clock_t start );
	bool	endGame( void );

private:
	int				bSpeed;
	int				eSpeed;
	int				eSpeed2;

	bool			direction;


	bool			_start;
	bool			_finish;

	double			dur;
	std::clock_t 	start;
	unsigned int	_width;
	unsigned int	_height;

	Player			player;
	Enemy			enemies[12];
	Bullet			bullets[42];

};

#endif
