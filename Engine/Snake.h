#pragma once
#include "Board.h"
#include "Location.h"
#include <math.h>
#include "Goal.h"
#include <random>
class Snake
{

private:
	class Segment {

	private:
		Location location;
		Color color;

	public:
		Segment() {
			color = { 255,255,255 };
		}
		~Segment() {}

		void Move(const Location& deltaL);
		void setLocation(Location other);
		Location getLocation() const;
		Color getColor() const;
		void setColor(const Color in_c);
	};


public:
	Snake();
	~Snake();
	void Move(Location deltaL, Board& board);
	void Draw(Board& board);
	void Eat(Goal& goal);
	Location getHeadLocation() const;
	bool ateItself() const;

private:
	static constexpr int maxLength = 300;
	int nSegments;
	Segment segments[maxLength];
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> redDist;
	std::uniform_int_distribution<int> blueDist;



};

