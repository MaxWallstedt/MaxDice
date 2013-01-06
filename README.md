# MaxDice

### About

MaxDice is a cross-platform text mode dice emulator. The advantage of using MaxDice over real dice is that you can instantly alter the die's amount of sides. It's also less noisy and will not fall off the table as easily.

When you start MaxDice, you see a fabulous welcome screen (created by me). Press 'enter' to enter or 'q' to exit the program ('q' is short for "quit"). Once you've entered, type in the amount of sides you wish your die to have (not 0), and press 'enter'. Now you see what the die rolled. If you wish to roll the die once again with the same amount of sides, just press 'enter' as many times as you please. If you however decide that you would rather change the amount of sides for the next roll, simply type in a new number and press 'enter' to continue.

Remember that a die can't have more than 2^(31) - 1 sides (2,147,483,647 sides). If you enter a number greater than that, the program will behave strange. To fix this behaviour, simply type a number that is within the range and press 'enter'.

### Pre-compiled binary

In the folder "Win32", there is a pre-compiled executable file for those using a Windows operating system and do not wish to compile the source code. I will work on both 32-bit and 64-bit versions of Windows.  
If you don't trust this file to be compiled from the unaltered source code in the "src" folder, or simply don't neeed it, feel free to delete it.

There is however no pre-compiled binary file for execution on a UNIX-like system, like GNU/Linux or Mac OS X. If you are using a UNIX-like system, you probably know how to compile a program from the source code. If otherwise, you may figure it out from the instructions below.

### Compile instructions

There are two compile scripts in the folder "compile_scripts", one for Windows and one for GNU/Linux. The one for GNU/Linux will probably work on any UNIX-like system. The scripts will create an executable file in the root of this program folder.

To compile the program, you will need:

1. A C compiler. I only test my programs in GNU's C compiler gcc. On Windows, I recommend MinGW, which is a port of the GNU toolchain (GNU Compiler Collection and GNU Binutils).
2. A Curses library. On UNIX-like systems, I recommend ncurses/ncursesw, but on Windows, PDCurses works better. PDCurses can be a bit complicated to install, but I will not write about that here.

###### Compile commands:

I will assume that you're standing in the root of this program (top folder "MaxDice").

UNIX-like systems:
```bash
user@machine:/path/to/MaxDice$ gcc -Wall /src/*.c -o MaxDice -lncursesw
```

Windows:
```
C:\path\to\MaxDice> gcc -Wall /src/*.c -o MaxDice.exe -lpdcurses
```

### License

MaxDice is [Free Software](http://www.gnu.org/philosophy/free-sw.html) under [GNU General Public License version 3 (GPLv3)](http://www.gnu.org/licenses/gpl.html). See the file "COPYING" for details.

regards  
Max Wällstedt