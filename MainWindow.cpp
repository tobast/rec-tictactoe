
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

#include "MainWindow.h"
using namespace sf;

MainWindow::MainWindow(std::string title, int w, int h) :
	win(), gameArea(win)
{
	win.create(VideoMode(w, h), title);
	win.setVerticalSyncEnabled(true);
	
	render();
}

void MainWindow::exec()
{
	Clock clock;
	while(win.isOpen())
	{
		clock.restart();

		Event event;
		while(win.pollEvent(event))
		{
			// Processing the different events.
			if(event.type == sf::Event::Closed)
				win.close();
		}

		render();

		// Sleeping 10ms - ellapsed (100fps max. framerate)
		sleep(milliseconds(10) - clock.getElapsedTime());
	}
}

void MainWindow::render()
{
	win.clear(Color::White);
	gameArea.render();
	win.display();
}
