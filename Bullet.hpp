#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entitie.hpp"
#include "Coordinates.hpp"

class Bullet : public Entitie
{

public:
    Bullet( void );
	Bullet( Bullet const & src );
	~Bullet( void );

	Bullet & operator=( Bullet const & rhs );

	bool	alive( void ) const;
	void	setLiveStatus( bool liveStatus );

private:
	bool	_alive;

};

#endif