#include "Goal.h"



Goal::Goal(Board & b) :
	board(b),
	rng(rd()),
	locationDistX(0, board.getWidth()),
	locationDistY(0, board.getHeight())
{
	location = { locationDistX(rng),locationDistY(rng) };
	color = Colors::Red;
}


Goal::~Goal()
{
}

void Goal::Draw() const
{
	board.Draw(location, color);
}

void Goal::Move()
{
	location = { locationDistX(rng),locationDistY(rng) };
}

Location Goal::getLocation() const
{
	return location;
}

int Goal::getDimension() const
{
	return dimension;
}
