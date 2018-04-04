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

int Board::getEgdeWidth() const
{
	return egdeWidth;
}

int Board::getLeftCornerX() const
{
	return leftCornerX;
}
int Board::getLeftCornerY() const
{
	return leftCornerY;
}

int Board::getFieldSize() const
{
	return fieldSize;
}

bool Board::isOutOfBoard(Location& in_location) const
{
	return in_location.x < (leftCornerX / fieldSize) || in_location.x > width
		|| in_location.y < (leftCornerY / fieldSize) || in_location.y > height;
}

void Board::DrawEdges()
{
	// Vertical left
	gfx.DrawRectangleDim(egdeInitialPosOffset, egdeInitialPosOffset, egdeWidth, 
							Graphics::ScreenHeight - 2*egdeInitialPosOffset, { 0, 161, 243 });

	// Vertical right
	gfx.DrawRectangleDim(Graphics::ScreenWidth - egdeWidth - egdeInitialPosOffset, egdeInitialPosOffset,
							egdeWidth, Graphics::ScreenHeight - 2*egdeInitialPosOffset, { 0, 161, 243 });

	// Horizontal top
	gfx.DrawRectangleDim(egdeWidth + egdeInitialPosOffset, egdeInitialPosOffset, 
							Graphics::ScreenWidth - egdeWidth - 2*egdeInitialPosOffset, egdeWidth, { 0, 161, 243 });

	//  Horizontal bottom
	gfx.DrawRectangleDim(egdeWidth + egdeInitialPosOffset,Graphics::ScreenHeight - egdeWidth - egdeInitialPosOffset,
							Graphics::ScreenWidth - egdeWidth - 2*egdeInitialPosOffset, egdeWidth, { 0, 161, 243 });

}


