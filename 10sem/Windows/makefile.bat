@echo off

set "USU=lib\user"
set "STR=lib\str"

gcc -c main.c -o main.o

gcc -c %USU%.c -o %USU%.o

gcc -c %STR%.c -o %STR%.o

gcc main.o %USU%.o %STR%.o -o main.exe

if "%1"=="clean" goto clean
if "%1"=="run" goto run
goto end

:clean
del *.o
del lib\*.o
del main.exe

:run
cls
.\main.exe

:end
