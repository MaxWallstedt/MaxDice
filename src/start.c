/************************************************************************/
/*                 Copyright © 2012-2013 Max Wällstedt                  */
/*                                                                      */
/* This file is part of MaxDice.                                        */
/*                                                                      */
/* MaxDice is free software: you can redistribute it and/or modify      */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or    */
/* (at your option) any later version.                                  */
/*                                                                      */
/* MaxDice is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of       */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        */
/* GNU General Public License for more details.                         */
/*                                                                      */
/* You should have received a copy of the GNU General Public License    */
/* along with MaxDice.  If not, see <http://www.gnu.org/licenses/>.     */
/*                                                                      */
/************************************************************************/

#include "maxdice.h"

void start(void)
{
	int maxy, maxx, max = 0, y = 3, i, die, blankdiff;

	getmaxyx(stdscr, maxy, maxx);
	maxy--;
	maxx--;

	mvprintw(0, 0, "========== MaxDice ==========");
	mvprintw(2, 0, "Enter the die's amount of sides: ");

	refresh();

	if (get_max_1(&max) == 0)
		return;

	while (1) {
		mvprintw(y++, 0, "Die roll: ");
		die = roll_dice(&max);
		blankdiff = blank_diff(max, die);

		for (i = 0; i < blankdiff; i++)
			printw(" ");

		printw("%d of %d\n", die, max);

		if (y > maxy) {
			y -= 2;
			move_up(&maxy, &maxx);
		}

		if (get_max_2(&max, &y) == 0)
			return;

		if (y > maxy) {
			y -= 2;
			move_up(&maxy, &maxx);
		}
	}
}