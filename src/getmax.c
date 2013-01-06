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

int get_max_1(int *ptrmax)
{
	int key, count = 0, x = 33;

	do {
		key = getch();

		if (key >= '0' && key <= '9') {
			*ptrmax = *ptrmax * 10 + key - '0';
			mvaddch(2, x++, key);
			count++;
		}

		else if ((key == 8 || key == 127) && count > 0) {
			*ptrmax /= 10;
			mvaddch(2, --x, ' ');
			move(2, x);
			count--;
		}

		else if (key == 'q')
			return 0;

		else if ((key == '\n' || key == '\r' || key == 459) && *ptrmax != 0)
			return 1;
	} while (1);
}

int get_max_2(int *ptrmax, int *ptry)
{
	int key, count = 0, x = 0, temp = *ptrmax;

	*ptrmax = 0;

	do {
		key = getch();

		if (key >= '0' && key <= '9') {
			*ptrmax = *ptrmax * 10 + key - '0';
			mvaddch(*ptry, x++, key);
			count++;
		}

		else if ((key == 8 || key == 127) && count > 0) {
			*ptrmax /= 10;
			mvaddch(*ptry, --x, ' ');
			move(*ptry, x);
			count--;
		}

		else if (key == 'q')
			return 0;

		else if (key == '\n' || key == '\r' || key == 459) {
			if (*ptrmax == 0)
				*ptrmax = temp;

			(*ptry)++;
			return 1;
		}
	} while (1);
}