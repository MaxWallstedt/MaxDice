/************************************************************************/
/*                    Copyright © 2013 Max Wällstedt                    */
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

int
roll_die (int number)
{
    return (rand () % number + 1);
}

int
blankdiff (int big, int small)
{
    int i = 1, j = 1;

    while (big >= 10)
    {
        big /= 10;
        i++;
    }

    while (small >= 10)
    {
        small /= 10;
        j++;
    }

    return (i - j);
}

void
start_maxdice (int number, int splash)
{
    int maxy, maxx, y = 1, i, dieroll;
    char numstr[256] = {0};

    srand (time (NULL));
    initscr ();
    noecho ();
    keypad (stdscr, TRUE);
    meta (stdscr, TRUE);
    nodelay (stdscr, FALSE);
    notimeout (stdscr, TRUE);
    raw ();
    curs_set (0);

    getmaxyx (stdscr, maxy, maxx);

    if (splash == 1)
    {
        if (maxy < 23)
        {
            resize_term (23, maxx);
            maxy = 23;
        }

        if (maxx < 41)
        {
            resize_term (maxy, 41);
            maxx = 41;
        }

        if (splash_screen () == 1)
        {
            endwin ();
            return;
        }
    }

    getmaxyx (stdscr, maxy, maxx);
    first_draw (maxx);

    if (number == 0)
    {
        mvprintw (2, 0, "Enter the die's amount of sides: ");

        if (mvreadstr (2, 33, numstr, maxx - 34, 1) == 1)
        {
            endwin ();
            return;
        }

        number = str_to_int (numstr);

        move (3, 0);
        y = 3;
    }

    while (1)
    {
        getmaxyx (stdscr, maxy, maxx);
        first_draw (maxx);

        if (y >= maxy)
            move_up (&y, maxy, maxx);

        for (i = 0; i < maxx; i++)
            mvaddch (y, i, ' ');

        dieroll = roll_die (number);
        mvprintw (y, 0, "Die roll: ");

        for (i = 0; i < blankdiff (number, dieroll); i++)
            addch (' ');

        printw ("%d of %d", dieroll, number);

        y++;

        if (y >= maxy)
            move_up (&y, maxy, maxx);

        if (mvreadstr2 (y, 0, numstr, maxx - 1, 1) == 1)
        {
            endwin ();
            return;
        }

        if (str_to_int (numstr) != 0)
            number = str_to_int (numstr);

        y++;
    }
}