
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

GameArea::GameArea(RenderWindow& win, Rect<int> zone) :
	win(win), zone(zone)
{
}

void GameArea::render()
{
	int colWidth = zone.width / 3, rowHeight = zone.height / 3;
	for(int row=0; row < 3; row++)
	{
		for(int col=0; col < 3; col++)
		{
			Rect<int> subZone(col * colWidth + zone.left, row * rowHeight + zone.top,
					colWidth, rowHeight);
			drawTTT(subZone, Color(0x25, 0x4e, 0xc4), 4, 4);
		}
	}

	drawTTT(zone, Color::Black, 8, 4);
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

