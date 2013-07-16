
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

class GameArea
{
	public:
		GameArea(sf::RenderWindow& win);
		void render();

	private:
		sf::RenderWindow& win;
};

#endif//DEF_GAMEAREA

