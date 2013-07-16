
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

#include "GameArea.h"
using namespace sf;

GameArea::GameArea(RenderWindow& win, Rect<int> zone, GameStatus& gameStatus) :
	win(win), zone(zone), gameStatus(gameStatus)
{
}

void GameArea::render()
{
	const int colWidth = zone.width / 3, rowHeight = zone.height / 3;

	RectangleShape nextNestedRect;
	if(gameStatus.nextNested == 9) // whole board
	{
		nextNestedRect.setSize(Vector2f(zone.width, zone.height));
		nextNestedRect.setPosition(zone.left, zone.top);
	}
	else // nested ttt
	{
		nextNestedRect.setSize(Vector2f(colWidth, rowHeight));
		nextNestedRect.setPosition((gameStatus.nextNested % 3) * colWidth + zone.left,
				(gameStatus.nextNested/3) * rowHeight + zone.top);
	}
	nextNestedRect.setFillColor(Color(0xBA, 0xAC, 0x44)); // Yellow
	win.draw(nextNestedRect);

	for(int row=0; row < 3; row++)
	{
		for(int col=0; col < 3; col++)
		{
			Rect<int> subZone(col * colWidth + zone.left, row * rowHeight + zone.top,
					colWidth, rowHeight);
			drawTTT(subZone, Color(0x25, 0x4e, 0xc4), 4, 0);
		}
	}

	drawTTT(zone, Color::Black, 8, 0);

	for(int over=0; over < 9; over++)
	{
		for(int nested=0; nested < 9; nested++)
		{
			switch(gameStatus.board[over][nested])
			{
				case CIRCLE_CELL:
					drawCircle(Cell(over, nested));
					break;
				case CROSS_CELL:
					drawCross(Cell(over, nested));
					break;
				default:
					break;
			}
		}
	}
}

GameArea::Cell GameArea::getCellOf(int x, int y) const
{
	Cell cell;
	x -= zone.left;
	y -= zone.top;

	if(x < 0 || x >= zone.width || y < 0 || y > zone.height)
		return cell;

	int row = 3*y / zone.height, col = 3*x / zone.width;
	cell.ttt = row*3+col;

	x -= col * zone.width/3;
	y -= row * zone.height/3;

	cell.nested = 3 * ((9*y)/zone.height) + ((9*x)/zone.width);

	return cell;
}

bool GameArea::playOn(GameArea::Cell cell)
{
	if(gameStatus.board[cell.ttt][cell.nested] != EMPTY_CELL)
		return false;
	else if(gameStatus.nextNested != cell.ttt && gameStatus.nextNested != 9)
		return false;

	if(gameStatus.isCircleTurn)
		gameStatus.board[cell.ttt][cell.nested] = CIRCLE_CELL;
	else
		gameStatus.board[cell.ttt][cell.nested] = CROSS_CELL;

	gameStatus.boardRemainingCells[cell.ttt]--;

	gameStatus.isCircleTurn ^= 1; // switch turns

	if(gameStatus.boardRemainingCells[cell.nested] > 0)
		gameStatus.nextNested = cell.nested;
	else
		gameStatus.nextNested = 9; // Play everywhere

	// TODO check winning position

	return true;
}

void GameArea::drawTTT(Rect<int> area, Color color, const int thickness, const int margin)
{
	const int colWidth = area.width / 3, rowHeight = area.height / 3;

	RectangleShape rect;
	rect.setFillColor(color);
	for(int line=1; line < 3; line++)
	{
		rect.setSize(Vector2f(thickness, area.height - 2*margin));
		rect.setPosition(area.left + line * colWidth - thickness/2,
				area.top + margin);
		win.draw(rect);

		rect.setSize(Vector2f(area.width - 2*margin, thickness));
		rect.setPosition(area.left + margin,
				area.top + line * rowHeight - thickness/2);
		win.draw(rect);
	}
}

void GameArea::drawCross(GameArea::Cell cell)
{
	const Color color = Color(0xAB, 0x14, 0x00); // Red
	const int margin = 12;
	int length = sqrt(pow(zone.width/9 - 2*margin, 2) + pow(zone.height/9 - 2*margin, 2));
	
	RectangleShape rect(Vector2f(4, length));
	rect.setOrigin(2,0);
	rect.setFillColor(color);

	rect.setPosition(zone.left + (cell.ttt%3)*(zone.width/3) +
			(cell.nested%3)*(zone.width/9) + margin,
		zone.top + (cell.ttt/3)*(zone.height/3) +
			(cell.nested/3)*(zone.height/9) + margin);
	rect.setRotation(315);
	win.draw(rect);

	rect.setPosition(zone.left + (cell.ttt%3)*(zone.width/3) +
			(cell.nested%3)*(zone.width/9) + margin,
		zone.top + (cell.ttt/3)*(zone.height/3) +
			(cell.nested/3 + 1)*(zone.height/9) - margin);
	rect.setRotation(225);
	win.draw(rect);
}

void GameArea::drawCircle(GameArea::Cell cell)
{
	const Color color = Color(0x3E, 0xA4, 0x1C); // Green
	const int margin = 12, thickness=4;

	CircleShape circle(zone.height/18 - margin, 60);
	circle.setFillColor(Color(0,0,0,0)); // Transparent
	circle.setOutlineColor(color);
	circle.setOutlineThickness(thickness);
	circle.setPosition(zone.left + (cell.ttt%3)*(zone.width/3) +
			(cell.nested%3)*(zone.width/9) + margin,
		zone.top + (cell.ttt/3)*(zone.height/3) +
			(cell.nested/3)*(zone.height/9) + margin);
	win.draw(circle);
}

