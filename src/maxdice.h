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

#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "readstring.h"

#define VERSION_NUMBER "1.0"

extern void start_maxdice (int number, int splash);
extern void move_up (int *y, int maxy, int maxx);
extern void first_draw (int maxx);
extern int splash_screen ();
extern int str_to_int (char *str);