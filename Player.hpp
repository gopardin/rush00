#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entitie.hpp"
#include "Coordinates.hpp"

class Player : public Entitie
{

public:
    Player( );
	Player( Player const & src );
	~Player( void );

	Player & operator=( Player const & rhs );



};

#endif