#pragma once
#include "Location.h"
#include "Colors.h"
#include "Board.h"
#include "random"

class Goal
{
public:
	Goal(Board &b);
	~Goal();
	void Draw() const;
	Location Move();
	Location getLocation() const;
	int getDimension() const;
private:
	Board & board;
	Location location;
	Color color;
	int dimension;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> locationDistX;
	std::uniform_int_distribution<int> locationDistY;

};

