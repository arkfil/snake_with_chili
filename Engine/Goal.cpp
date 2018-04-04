#include "Goal.h"



Goal::Goal(Board & b) :
	board(b),
	rng(rd()),
	locationDistX(board.getLeftCornerX()/ board.getEgdeWidth(), board.getWidth()),
	locationDistY(board.getLeftCornerY()/ board.getEgdeWidth(), board.getHeight())
{
	Move();
	color = Colors::Red;
}


Goal::~Goal()
{
}

void Goal::Draw() const
{
	board.Draw(location, color);
}

Location Goal::Move()
{
	location = { locationDistX(rng),locationDistY(rng) };
	return location;
}

Location Goal::getLocation() const
{
	return location;
}

int Goal::getDimension() const
{
	return dimension;
}
