/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	board( gfx ),
	snake(),
	goal(board)

{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{


	if (wnd.kbd.KeyIsPressed(VK_RIGHT) && innertionDeltaL.x != -1) {
		//snake.Move({ 1,0 }, board);
		innertionDeltaL = { 1,0 };
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN) && innertionDeltaL.y != -1) {
		//snake.Move({ 0,1 }, board);
		innertionDeltaL = { 0,1 };
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT) && innertionDeltaL.x != 1) {
		//snake.Move({ -1,0 }, board);
		innertionDeltaL = { -1,0 };
	}
	else if (wnd.kbd.KeyIsPressed(VK_UP) && innertionDeltaL.y != 1) {
		//snake.Move({ 0,-1 }, board);
		innertionDeltaL = { 0,-1 };
	}
	if (refreshCounter == 10 && !gameIsOver) {
		gameIsOver = board
						.isOutOfBoard(snake.getHeadLocation() + innertionDeltaL)
						|| snake.ateItself()
			;

		auto g = snake.ateItself();
		if (gameIsOver) return;

		snake.Eat(goal);
		snake.Move(innertionDeltaL, board);
		refreshCounter = 0;
		
		//gameIsOver = snake.isGameOver(board);


	}

	++refreshCounter;


}
////////////////////////////////////////////////////////////////

//bool Snake::isGameOver(Board &board) const
//{
//	if (((segments[0].getLocation()).x + board.getFieldSize() >= board.getWidth())
//		|| ((segments[0].getLocation()).y + board.getFieldSize() > board.getHeight())
//		|| ((segments[0].getLocation()).x <= 0)
//		|| ((segments[0].getLocation()).y <= 0))
//		return true;
//
//	for (int i = 1; i < nSegments; ++i) {
//		if (segments[0].getLocation() == segments[i].getLocation())
//			return true;
//	}
//	return false;
//}


//std::random_device rd;
//std::mt19937 rng(rd());
//std::uniform_int_distribution<int> colorDist(0, 255);


void Game::ComposeFrame()
{
	
	snake.Draw(board);
	goal.Draw();
}
