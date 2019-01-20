#include "Entitie.hpp"
#include <iostream>

Entitie::Entitie( void ) {}

Entitie::Entitie( char type, Coordinates const & max) : _type(type), _max(max) {}

Entitie::Entitie( Entitie const & src )
{
	if (this != &src)
		*this = src;
}

Entitie::~Entitie( void ) {}

char			Entitie::getType( void ) const { return this->_type; }
void			Entitie::setType( char const & type ) { this->_type = type; }

Coordinates		Entitie::getMaxCoordinates( void ) const { return this->_max; }
void			Entitie::setMaxCoordinates( Coordinates const & coordinates ) { this->_max = coordinates; }

Coordinates		Entitie::getAbsCoordinates( void ) const { return this->_abs; }
void			Entitie::setAbsCoordinates( Coordinates const & coordinates ) { this->_abs = coordinates; }

Entitie & Entitie::operator=( Entitie const & rhs )
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_max = rhs._max;
		this->_abs = rhs._abs;
	}
	return *this;
}
