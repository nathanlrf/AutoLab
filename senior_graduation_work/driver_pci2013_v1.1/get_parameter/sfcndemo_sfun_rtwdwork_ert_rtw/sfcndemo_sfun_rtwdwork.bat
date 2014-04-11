call "%VS110COMNTOOLS%..\..\VC\vcvarsall.bat"

cd .

if "%1"=="" (nmake -f sfcndemo_sfun_rtwdwork.mk all) else (nmake -f sfcndemo_sfun_rtwdwork.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
