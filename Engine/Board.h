#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "Location.h"
#include <assert.h>

class Board
{

public:
	Board(Graphics &gfx);
	~Board();
	void Draw(const Location l, const Color c);
	int getHeight() const;
	int getWidth() const;
	int getFieldSize() const;
	bool isOutOfBoard(Location& in_location) const;
private:
	static constexpr int fieldSize = 20;
	static constexpr int width = Graphics::ScreenWidth / fieldSize;
	static constexpr int height = Graphics::ScreenHeight / fieldSize;
	Graphics& gfx;


};

