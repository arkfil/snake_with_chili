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
	int getEgdeWidth() const;
	int getLeftCornerX() const;
	int getLeftCornerY() const;
	int getFieldSize() const;
	bool isOutOfBoard(Location& in_location) const;
	void DrawEdges();


private:
	static constexpr int egdeWidth = 10;
	static constexpr int egdeInitialPosOffset = 10;
	static constexpr int fieldSize = 20;
	static constexpr int leftCornerX = egdeWidth + egdeInitialPosOffset;
	static constexpr int leftCornerY = egdeWidth + egdeInitialPosOffset;
	static constexpr int width = (Graphics::ScreenWidth - egdeWidth - egdeInitialPosOffset) / fieldSize -1;
	static constexpr int height = (Graphics::ScreenHeight - egdeWidth - egdeInitialPosOffset) / fieldSize -1;
	Graphics& gfx;


};

