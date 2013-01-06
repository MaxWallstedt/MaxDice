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

int blank_diff(int big, int small)
{
	int i = 1, j = 1;

	while (big >= 10) {
		big /= 10;
		i++;
	}

	while (small >= 10) {
		small /= 10;
		j++;
	}

	return (i - j);
}

void move_up(int *y, int *x)
{
	int i, j, ch;

	for (i = 1; i <= (*y - 2); i++)
		for (j = 0; j <= *x; j++) {
			ch = mvinch(i + 2, j);
			mvaddch(i, j, ch);
		}

	for (i = 0; i <= *x; i++) {
		mvaddch(*y - 1, i, ' ');
		mvaddch(*y, i, ' ');
	}

	move(*y - 1, 0);

	return;
}