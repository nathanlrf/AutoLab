set MATLAB=D:\Program Files\MATLAB\R2013b

cd .

if "%1"=="" (D:\PROGRA~1\MATLAB\R2013b\bin\win32\gmake -f s_fun_lesson1.mk all) else (D:\PROGRA~1\MATLAB\R2013b\bin\win32\gmake -f s_fun_lesson1.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
