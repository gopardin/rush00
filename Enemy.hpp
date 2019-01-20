#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entitie.hpp"
#include "Coordinates.hpp"

class Enemy : public Entitie
{

public:
	Enemy( void );
	Enemy( Enemy const & src );
	~Enemy( void );

	bool	alive( void ) const;
	void	setLiveStatus( bool liveStatus );

	Enemy & operator=( Enemy const & rhs );

private:
	bool	_alive;

};

#endif
