@echo off
set MATLAB=D:\Program Files\MATLAB\R2013b
"%MATLAB%\bin\win32\gmake" -f sfbuilder_bususage.mk  RSIM_SOLVER_SELECTION=2 OPTS="-DON_TARGET_WAIT_FOR_START=0"
