call "%ONEAPI_ROOT%\setvars.bat"

if exist "%VS2022INSTALLDIR%\Common7\IDE\devenv.exe" (
    start "Visual Studio 2022 with Intel Compiler" /B "%VS2022INSTALLDIR%\Common7\IDE\devenv.exe" .
)