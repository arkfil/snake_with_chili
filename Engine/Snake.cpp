#include "Snake.h"


Snake::Snake() : rng(rd()), redDist(0, 52), blueDist(0, 52)
{							
	nSegments = 3;
	segments[0].setLocation({ 4, 2 });
	segments[1].setLocation({ 3, 2 });
	segments[2].setLocation({ 2, 2 });

	segments[0].setColor(Colors::Yellow);
	segments[1].setColor({ (unsigned char)redDist(rng), (unsigned char)130, (unsigned char)blueDist(rng) });
	segments[2].setColor({ (unsigned char)redDist(rng), (unsigned char)130, (unsigned char)blueDist(rng) });

}

Snake::~Snake()
{
}

void Snake::Move(Location deltaL, Board& board)
{
	for (int i = nSegments; i > 0; --i) {
			segments[i].setLocation(segments[i - 1].getLocation());
	}
	segments[0].Move(deltaL);
}

void Snake::Draw(Board& board)
{
	for (int i = 0; i < nSegments; ++i) {
		board.Draw(segments[i].getLocation(), segments[i].getColor());
	}
}

bool Snake::TryEat(Goal & goal)
{
	if (segments[0].getLocation()
		.isOvelaping(goal.getLocation()))
	{
		goal.Move();
		while (this->isInTile(goal.getLocation())) {
			goal.Move();
		}

		segments[nSegments].setLocation(segments[0].getLocation());
		segments[nSegments].setColor({ (unsigned char)redDist(rng),(unsigned char)130,(unsigned char)blueDist(rng) });
		++nSegments;
		return true;
	}
	return false;
}

Location Snake::getHeadLocation() const
{
	return segments[0].getLocation();
}

bool Snake::ateItself() const
{
	for (int i = 1; i < nSegments; ++i) {
		if (segments[0].getLocation() == segments[i].getLocation())
			return true;
	}
	return false;
}

bool Snake::isInTile(Location in_location)
{
	for (int i = 0; i < nSegments; ++i) {
		if (in_location == segments[i].getLocation())
			return true;
	}
	return false;
}

void Snake::Segment::Move(const Location & deltaL)
{
	if (std::abs(deltaL.x)+ abs(deltaL.y) == 1) {
		location = location + deltaL;
	}
}

void Snake::Segment::setLocation(Location other)
{
	location = other;
}

Location Snake::Segment::getLocation() const
{
	return location;
}

Color Snake::Segment::getColor() const
{
	return color;
}

void Snake::Segment::setColor(const Color in_c)
{
	color = in_c;
}
