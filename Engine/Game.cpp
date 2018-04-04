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
#include "PutpixelScreens.h"

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
Location dummyLoc{ -2,-2 };
void Game::UpdateModel()
{
	if (!startPressed) {
		startPressed = wnd.kbd.KeyIsPressed(VK_RETURN);
	}
	else {

	
		
	if (innertionDeltaL[1] == dummyLoc) {
		iterationClicked = false;
	}
	else {
		innertionDeltaL[0] = innertionDeltaL[1];
		innertionDeltaL[1] = innertionDeltaL[2];
		innertionDeltaL[2] = innertionDeltaL[3];
		innertionDeltaL[3] = innertionDeltaL[4];
		innertionDeltaL[4] = dummyLoc;
		iterationClicked = true;
	}

	//if (innertionDeltaL[1] == dummyLoc)
	//	iterationClicked = false;
	//else {
	//	innertionDeltaL[0] = innertionDeltaL[1];
	//	iterationClicked = true;
	//}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT) && innertionDeltaL[0].x != -1 ) {
		if (!iterationClicked) {
			innertionDeltaL[0] = { 1,0 };
			iterationClicked = true;
		}
		else if(innertionDeltaL[1] == dummyLoc)
			innertionDeltaL[1] = { 1,0 };
		else if (innertionDeltaL[2] == dummyLoc)
			innertionDeltaL[2] = { 1,0 };
		else if (innertionDeltaL[3] == dummyLoc)
			innertionDeltaL[3] = { 1,0 };
		else if (innertionDeltaL[4] == dummyLoc)
			innertionDeltaL[4] = { 1,0 };
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT) && innertionDeltaL[0].x != 1 ) {
		if (!iterationClicked){
			innertionDeltaL[0] = { -1,0 };		
			iterationClicked = true;
		}
		else if (innertionDeltaL[1] == dummyLoc)
			innertionDeltaL[1] = { -1,0 };
		else if (innertionDeltaL[2] == dummyLoc)
			innertionDeltaL[2] = { -1,0 };
		else if (innertionDeltaL[3] == dummyLoc)
			innertionDeltaL[3] = { -1,0 };
		else if (innertionDeltaL[4] == dummyLoc)
			innertionDeltaL[4] = { -1,0 };
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN) && innertionDeltaL[0].y != -1) {
		if (!iterationClicked) {
			innertionDeltaL[0] = { 0,1 };
			iterationClicked = true;
		}
		else if (innertionDeltaL[1] == dummyLoc)
			innertionDeltaL[1] = { 0,1 };
		else if (innertionDeltaL[2] == dummyLoc)
			innertionDeltaL[2] = { 0,1 };
		else if (innertionDeltaL[3] == dummyLoc)
			innertionDeltaL[3] = { 0,1 };
		else if (innertionDeltaL[4] == dummyLoc)
			innertionDeltaL[4] = { 0,1 };
	}
	else if (wnd.kbd.KeyIsPressed(VK_UP) && innertionDeltaL[0].y != 1 ) {
		if (!iterationClicked) {
			innertionDeltaL[0] = { 0,-1 };
			iterationClicked = true;
		}
		else if (innertionDeltaL[1] == dummyLoc)
			innertionDeltaL[1] = { 0,-1 };
		else if (innertionDeltaL[2] == dummyLoc)
			innertionDeltaL[2] = { 0,-1 };
		else if (innertionDeltaL[3] == dummyLoc)
			innertionDeltaL[3] = { 0,-1 };
		else if (innertionDeltaL[4] == dummyLoc)
			innertionDeltaL[4] = { 0,-1 };


	}
	


	if (refreshCounter >= snakeRefreshRate && !gameIsOver && startPressed) {
		gameIsOver = board
						.isOutOfBoard(snake.getHeadLocation() + innertionDeltaL[0])
						|| snake.ateItself()
			;

		//auto g = snake.ateItself();
		if (gameIsOver) return;

		if (snake.TryEat(goal)) {
			if (snakeRefreshRate >= 240)
				snakeRefreshRate-=15;
			else if(snakeRefreshRate >= 180)
				snakeRefreshRate -= 11;
			else if (snakeRefreshRate >= 100)
				snakeRefreshRate -= 5;
			else if (snakeRefreshRate >= 80)
				snakeRefreshRate -= 1;
		}


		snake.Move(innertionDeltaL[0], board);
		//iterationClicked = false;

		refreshCounter = 0;
		
		//gameIsOver = snake.isGameOver(board);


	}
	

	
	refreshCounter += 18;
	}


}

void Game::ComposeFrame()
{


	if (gameIsOver) {
		PutpixelScreens::DrawGameOver(358, 268, gfx);
	}
	else if (!startPressed) {
		PutpixelScreens::DrawTitleScreen(325, 211, gfx);
	}
	else {
		board.DrawEdges();
		snake.Draw(board);
		goal.Draw();
	}

}
