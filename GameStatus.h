
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

#ifndef DEF_GAMESTATUS
#define DEF_GAMESTATUS

enum PlayerType
{
	EMPTY, CIRCLE, CROSS
};

struct GameStatus
{
	GameStatus() : nextNested(9), isCircleTurn(true)
	{
		for(int over=0; over < 10; over++)
		{
			for(int nest=0; nest < 9; nest++)
				board[over][nest] = EMPTY;
			boardRemainingCells[over]=9;
		}
	}

	int nextNested;
	bool isCircleTurn;
	
	PlayerType board[10][9]; // The 10th array contains informations on the nested board
	int boardRemainingCells[9];
};

#endif//DEF_GAMESTATUS

