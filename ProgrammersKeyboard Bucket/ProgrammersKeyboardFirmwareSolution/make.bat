cls
@echo off
echo Compiling your source code now...
sdcc main.c
if errorlevel 1 goto compileerror
echo compilation success.
echo Now packing ipx file to hex file
packihx < main.ihx > main.hex
if errorlevel 1 goto packerror
echo packing done!
dir main.*
goto exitpause
:compileerror
echo Error in compilation time.
goto exitpause
:packerror
echo error while packing file
goto exitpause
:exitpause
pause
