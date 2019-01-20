#ifndef ENTITIE_HPP
#define ENTITIE_HPP

#include "Coordinates.hpp"

class Entitie
{

public:
	Entitie( char type, Coordinates const & max);
	Entitie( Entitie const & src );
	Entitie( void );
	virtual ~Entitie( void );

	char 		getType( void ) const;
	void		setType( char const & type );

	Coordinates	getMaxCoordinates( void ) const;
	void		setMaxCoordinates( Coordinates const & coordinates );

	Coordinates	getAbsCoordinates( void ) const;
	void		setAbsCoordinates( Coordinates const & coordinates );

	Entitie &	operator=( Entitie const & rhs );

protected:
	char		_type;
	Coordinates	_max;
	Coordinates	_abs;

};

#endif
