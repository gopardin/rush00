#include "Bullet.hpp"
#include <iostream>


Bullet::Bullet( void) : Entitie('*', Coordinates(1, 1))
{
}

Bullet::Bullet( Bullet const & src ) : Entitie(src)
{
}

Bullet::~Bullet( void )
{
}

Bullet & Bullet::operator=( Bullet const & rhs )
{
    (void)rhs;
	return *this;
}

bool	Bullet::alive( void ) const { return this->_alive; }

void	Bullet::setLiveStatus( bool liveStatus ) { this->_alive = liveStatus; }

