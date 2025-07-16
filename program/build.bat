@echo off
cls

echo -----------------------------------------
echo     AVR Build System by Eng. Ahmed Bahaa
echo -----------------------------------------

:: Run the Makefile steps
echo Cleaning...
make clean
if errorlevel 1 goto :error

echo Syncing source files...
make sync
if errorlevel 1 goto :error

echo Building project...
make all
if errorlevel 1 goto :error

:: Show success message
echo.
echo ====================================================
echo            Build Process Completed [SUCCESS]
echo ====================================================
echo        Developed by Eng. Ahmed Bahaa Nasr
echo     Automotive Embedded SW Engineer [ADAS]
echo ====================================================
echo.

goto :end

:error
echo.
echo ====================================================
echo              Build Process Failed [ERROR]
echo ====================================================
echo     Please check the output above for details.
echo ====================================================
echo.
pause
exit /b 1

:end
pause
