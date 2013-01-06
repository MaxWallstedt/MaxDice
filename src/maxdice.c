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

int main(void)
{
	srand((unsigned int)time(NULL));
	setlocale(LC_CTYPE, "");
	initscr();
	raw();
	nonl();
	noecho();
	keypad(stdscr, TRUE);

	if (splash() == 1) {
		endwin();
		return 0;
	}

	start();

	endwin();
	return 0;
}