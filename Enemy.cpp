#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy( void ): Entitie('#', Coordinates(2, 2)), _alive(true)
{
}

Enemy::Enemy( Enemy const & src ) : Entitie(src)
{
}

Enemy::~Enemy( void )
{
}

bool	Enemy::alive( void ) const { return this->_alive; }

void	Enemy::setLiveStatus( bool liveStatus ) { this->_alive = liveStatus; }

Enemy & Enemy::operator=( Enemy const & rhs )
{
    (void)rhs;
	return *this;
}
