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

#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

extern int splash(void);
extern int roll_dice(int *max);
extern void start(void);
extern int get_max_1(int *ptrmax);
extern int get_max_2(int *ptrmax, int *ptry);
extern int blank_diff(int big, int small);
extern void move_up(int *y, int *x);