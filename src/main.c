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
main (int argc, char *argv[])
{
    int splash = 1, i, j, number = 0;

    setlocale (LC_CTYPE, "");

    for (i = 1; i < argc; i++)
    {
        if (strcmp (argv[i], "--nosplash") == 0
            || strcmp (argv[i], "-ns") == 0)
            splash = 0;

        else if (strcmp (argv[i], "--help") == 0
                 || strcmp (argv[i], "-h") == 0)
        {
            printf ("Usage: %s [options] [number]\n\n", argv[0]);
            printf ("Options:\n");
            printf ("  --nosplash / -ns");
            printf ("     ");
            printf ("Skips splash screen\n");
            printf ("  --help / -h");
            printf ("          ");
            printf ("Prints this help message\n");
            printf ("  --version / -v");
            printf ("       ");
            printf ("Prints program name, version and license\n\n");
            printf ("Number:\n");
            printf ("  If any program argument contains a number, ");
            printf ("the first one doing so will be\n");
            printf ("  the first die's amount of sides (skipping ");
            printf ("the first prompt).\n");
            printf ("  Any character in that argument that is not ");
            printf ("'0' to '9' will be ignored,\n");
            printf ("  for example \"--1foo3bar5\" becomes 135.\n");
            printf ("  If the entered number is 0, it will be ");
            printf ("interpreted as not entering a number.\n");
            printf ("  Entering a non-zero number as an argument ");
            printf ("disables splash screen.\n\n");
            printf ("Report bugs to <max.wallstedt@gmail.com>\n");
            printf ("MaxDice home page: ");
            printf ("<https://github.com/MaxWallstedt/MaxDice>\n");

            return 0;
        }

        else if (strcmp (argv[i], "--version") == 0
                 || strcmp (argv[i], "-v") == 0)
        {
            printf ("MaxDice %s\n", VERSION_NUMBER);
#ifdef WIN32
            printf ("Copyright (C) 2013 Max W\x84llstedt\n\n");
#else
            printf ("Copyright (C) 2013 Max Wällstedt\n\n");
#endif
            printf ("License GPLv3+: GNU General Public License ");
            printf ("version 3 or later\n");
            printf ("                ");
            printf ("<http://gnu.org/license/gpl.html>\n\n");
            printf ("This is free software: you are free to ");
            printf ("change and redistribute it.\n");
            printf ("There is NO WARRANTY, ");
            printf ("to the extent permitted by law.\n");

            return 0;
        }
    }

    for (i = 0; i < argc; i++)
    {
        j = 0;

        while (*(argv[i] + j) != '\0')
        {
            if (*(argv[i] + j) >= '0' && *(argv[i] + j) <= '9')
                number = number * 10 + *(argv[i] + j) - '0';

            j++;
        }

        if (number != 0)
        {
            i = argc;
            splash = 0;
        }
    }

    start_maxdice (number, splash);

    return 0;
}