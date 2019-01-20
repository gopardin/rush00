#include "Coordinates.hpp"
#include <iostream>

Coordinates::Coordinates( void ) : _x(0), _y(0) {}

Coordinates::Coordinates( unsigned int x, unsigned int y  ) : _x(x), _y(y) {}

Coordinates::Coordinates( Coordinates const & src )
{

	if (this != &src)
		*this = src;
}

Coordinates::~Coordinates( void )
{

}

unsigned int 			Coordinates::getX( void ) const { return this->_x; }
void				 	Coordinates::setX( unsigned int x ) { this->_x = x; }

unsigned int			Coordinates::getY( void ) const { return this->_y; }
void				 	Coordinates::setY( unsigned int y ) { this->_y = y; }

Coordinates & Coordinates::operator=( Coordinates const & rhs )
{

	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}
