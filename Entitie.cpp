#include "Entitie.hpp"
#include <iostream>

Entitie::Entitie( void )
{
//	std::cout << "Entitie: Default constructor called" << std::endl;
}

Entitie::Entitie( char type, Coordinates const & max) : _type(type), _max(max)
{
//	std::cout << "Entitie: Constructor with parameters called" << std::endl;
}

Entitie::Entitie( Entitie const & src )
{
	std::cout << "Entitie: Copy constructor called" << std::endl;
	if (this != &src)
		*this = src;
}

Entitie::~Entitie( void )
{
//	std::cout << "Entitie: Default destructor called" << std::endl;
}

char			Entitie::getType( void ) const { return this->_type; }
void			Entitie::setType( char const & type ) { this->_type = type; }

Coordinates		Entitie::getMaxCoordinates( void ) const { return this->_max; }
void			Entitie::setMaxCoordinates( Coordinates const & coordinates ) { this->_max = coordinates; }

Coordinates		Entitie::getAbsCoordinates( void ) const { return this->_abs; }
void			Entitie::setAbsCoordinates( Coordinates const & coordinates ) { this->_abs = coordinates; }

Entitie & Entitie::operator=( Entitie const & rhs )
{
	std::cout << "Entitie: assign operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_max = rhs._max;
		this->_abs = rhs._abs;
	}
	return *this;
}
