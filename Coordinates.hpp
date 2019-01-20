#ifndef COORDINATES_HPP
#define COORDINATES_HPP

class   Coordinates
{

public:
	Coordinates( void );
	Coordinates( unsigned int x, unsigned int y );
	Coordinates( Coordinates const & src );
	~Coordinates( void );

	unsigned int 			getX( void ) const;
	void				 	setX( unsigned int x );

	unsigned int			getY( void ) const;
	void				 	setY( unsigned int y );

	Coordinates & operator=( Coordinates const & rhs);

private:
	unsigned int  _x;
	unsigned int  _y;

};

#endif
