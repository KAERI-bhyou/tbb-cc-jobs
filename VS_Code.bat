call "%ONEAPI_ROOT%\setvars.bat"

if exist "%PROGRAMFILES%\Microsoft VS Code\Code.exe" (
    start "Visual Studio Code with Intel Compiler" /B "%PROGRAMFILES%\Microsoft VS Code\Code.exe" .
) else (
    start "Visual Studio Code with Intel Compiler (Userspace)" /B "%LocalAppData%\Programs\Microsoft VS Code\Code.exe" .
)