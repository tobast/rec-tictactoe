
/*
 * SOFTWARE:
 *   Recursive Tic-Tac-Toe
 * 
 * AUTHOR:
 *   Theophile BASTIAN "Tobast" <contact@tobast.fr>
 *
 * WEBSITE:
 *   http://tobast.fr/
 *
 * LICENCE:
 *   GNU GPL v3
 *
 * DESCRIPTION:
 *   This software implements a recursive version of the Tic-Tac-Toe.
 *
 * LICENCE HEADER:
 *   Copyright (C) 2013  BASTIAN Theophile
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/gpl.txt>.
 */

#ifndef DEF_GAMEAREA
#define DEF_GAMEAREA

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <cmath>

#include "GameStatus.h"

class GameArea
{
	public:
		struct Cell {
			Cell() : ttt(-1), nested(-1)  {}
			Cell(int ttt, int nested) :
				ttt(ttt), nested(nested) {}

			int ttt, nested;
		};

		GameArea(sf::RenderWindow* win, sf::Rect<int> zone, GameStatus& gameStatus);
		void setWindow(sf::RenderWindow* _win) { win = _win; }
		void render();
		Cell getCellOf(int x, int y) const;

		bool playOn(Cell cell);

	private:
		void drawTTT(sf::Rect<int> area, sf::Color color, const int thickness, const int margin);
		void drawCross(Cell cell, int alpha = 0xff);
		void drawCross(sf::Rect<int> area, int alpha=0xff);
		void drawCircle(Cell cell, int alpha = 0xff);
		void drawCircle(sf::Rect<int> area, int alpha = 0xff);

		PlayerType winnerOf(int nested); // 9 = overall ttt
		void gameWon(PlayerType winner);

	private:
		sf::RenderWindow* win;
		sf::Rect<int> zone;

		GameStatus& gameStatus;
};

#endif//DEF_GAMEAREA

