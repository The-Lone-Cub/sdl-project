@echo off
setlocal enabledelayedexpansion

set WORKSPACE_DIR=%CD%
set SOURCES=

rem Add all .cpp files to the SOURCES variable
for %%f in (%WORKSPACE_DIR%\src\*.cpp) do (
    set SOURCES=!SOURCES! %%f
)

rem Run the compiler with all the sources
g++ !SOURCES! -o %WORKSPACE_DIR%\bin\output.exe -I%WORKSPACE_DIR% -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_net -lSDL2_ttf

endlocal
