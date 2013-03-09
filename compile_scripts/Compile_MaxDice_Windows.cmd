@echo off
echo === Compiling... ===
gcc -Wall ../src/*.c -o ../MaxDice.exe -lpdcurses -static
pause
