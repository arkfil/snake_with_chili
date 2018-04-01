#include "Board.h"

Board::Board(Graphics & gfx) : gfx(gfx)
{
}

Board::~Board()
{
}

void Board::Draw(const Location l, const Color c)
{
	gfx.DrawRectangleDim(l.x*fieldSize+2,l.y*fieldSize+2,fieldSize-2,fieldSize-2,c);
}

int Board::getHeight() const
{
	return height;
}

int Board::getWidth() const
{
	return width;
}

int Board::getFieldSize() const
{
	return fieldSize;
}

bool Board::isOutOfBoard(Location& in_location) const
{
	return in_location.x < 0 || in_location.x > width
		|| in_location.y < 0 || in_location.y > height;
}


