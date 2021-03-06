/************************************************************************/
/*                    Copyright � 2013 Max W�llstedt                    */
/*                                                                      */
/* This file is part of MaxDice.                                        */
/*                                                                      */
/* MaxDice is free software: you can redistribute it and/or modify it   */
/* under the terms of the GNU General Public License as published by    */
/* the Free Software Foundation, either version 3 of the License, or    */
/* (at your option) any later version.                                  */
/*                                                                      */
/* MaxDice is distributed in the hope that it will be useful, but       */
/* WITHOUT ANY WARRANTY; without even the implied warranty of           */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                 */
/* See the GNU General Public License for more details.                 */
/*                                                                      */
/* You should have received a copy of the GNU General Public License    */
/* along with MaxDice. If not, see  <http://www.gnu.org/licenses/>.     */
/*                                                                      */
/************************************************************************/

#include "maxdice.h"

void
move_up (int *y, int maxy, int maxx)
{
    int i, j, ch;

    while (*y >= maxy)
    {
        for (j = 1; j < *y - 2; j++)
        {
            for (i = 0; i < maxx; i++)
            {
                ch = mvinch (j + 2, i);
                mvaddch (j, i, ch);
            }
        }

        for (i = 0; i < maxx; i++)
        {
            mvaddch (*y - 1, i, ' ');
            mvaddch (*y, i, ' ');
        }

        *y -= 2;
    }

    return;
}

void
first_draw (int maxx)
{
    int i;

    maxx -= 9;
    move (0, 0);

    if (maxx % 2 == 0)
    {
        maxx /= 2;

        for (i = 0; i < maxx; i++)
            addch ('=');

        printw (" MaxDice ");

        for (i = 0; i < maxx; i++)
            addch ('=');
    }

    else
    {
        maxx--;
        maxx /= 2;

        for (i = 0; i < maxx; i++)
            addch ('=');

        printw (" MaxDice ");

        for (i = 0; i <= maxx; i++)
            addch ('=');
    }

    move (1, 0);

    return;
}

int
splash_screen ()
{
	int key;

	mvprintw(0, 22, "II");
	mvprintw(1, 14, "IIIIIIIIIIII");
	mvprintw(2, 6, "IIIIIIIIIIIIIIIIIIIIIII");
	mvprintw(3, 4, "?IIIIIIIIIII7....IIIIIIIIIII");
	mvprintw(4, 4, "??IIIIIIIIIII....IIIIIIIIIIII");
	mvprintw(5, 5, "???IIIIIIIIIIIIIIIIIIIIIIIIII");
	mvprintw(6, 5, "?????IIIIIIIIIIIIIII777777777");
	mvprintw(7, 5, "?..????IIIIII7777777777.....7");
	mvprintw(8, 5, "??.???????777777777777.....77");
	mvprintw(9, 5, "??.???????77....777777....777");
	mvprintw(10, 5, "??????????7.....777777777777");
	mvprintw(11, 6, "?????????7.... 777777777777");
	mvprintw(12, 6, "?????????77777777....777777");
	mvprintw(13, 6, "?????????7777777.....777777");
	mvprintw(14, 6, "????..???77777777...7777..7");
	mvprintw(15, 7, "???...??7777777777777....7");
	mvprintw(16, 8, "???..??7777777777777....7");
	mvprintw(17, 9, "??????7....7777777777777");
	mvprintw(18, 11, "????.....77777777");
	mvprintw(19, 12, "???7..77777");
	mvprintw(20, 13, "??7777       MaxDice");
	mvprintw(22, 0, "Press 'Enter' to start, press 'q' to quit");

	refresh();

	do {
		key = getch();
	} while (key != '\n' && key != '\r' && key != 459 && key != 'q');

	erase();

	if (key == 'q')
		return 1;
	else
		return 0;
}