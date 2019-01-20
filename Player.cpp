#include "Player.hpp"
#include <iostream>


Player::Player( void ) : Entitie('#', Coordinates(3, 1))
{
}

Player::Player( Player const & src ) : Entitie(src)
{
}

Player::~Player( void )
{
}

Player & Player::operator=( Player const & rhs )
{
    (void)rhs;
	return *this;
}
