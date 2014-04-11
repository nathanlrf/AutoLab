###########################################################################
## Makefile generated for Simulink model 'sfcndemo_stvdtf'. 
## 
## Makefile     : sfcndemo_stvdtf.mk
## Generated on : Tue Apr 01 10:33:30 2014
## MATLAB Coder version: 2.5 (R2013b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)\sfcndemo_stvdtf.exe
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.
# MODELREF_LINK_RSPFILE   Include paths for the model reference build
# PERL                    PERL Tool
# GEN_LNK_SCRIPT          Perl script to generate the command file
# CMD_FILE                Command file

PRODUCT_NAME              = sfcndemo_stvdtf
MAKEFILE                  = sfcndemo_stvdtf.mk
COMPUTER                  = PCWIN
MATLAB_ROOT               = D:\PROGRA~1\MATLAB\R2013b
MATLAB_BIN                = D:\Program Files\MATLAB\R2013b\bin
MATLAB_ARCH_BIN           = D:\Program Files\MATLAB\R2013b\bin\win32
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:\Users\lenovo\Documents\MATLAB\senior_graduation_work\driver_pci2013_v1.1\get_parameter
ARCH                      = win32
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 1
TGT_FCN_LIB               = C89/C90 (ANSI)
MODELREF_LINK_RSPFILE_NAME = sfcndemo_stvdtf_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ..
MODELREF_LINK_RSPFILE     = sfcndemo_stvdtf_ref.rsp
PERL                      = $(MATLAB_ROOT)\sys\perl\win32\bin\perl.exe
GEN_LNK_SCRIPT            = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl
CMD_FILE                  = $(PRODUCT_NAME).lnk
NODEBUG                   = 1

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2012 v11.0 | nmake (32-bit Windows)
# Supported Version(s):    11.0
# ToolchainInfo Version:   R2013b
# Specification Revision:  1.0
# 

!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# NODEBUG
# cvarsdll
# cvarsmt
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

MEX_OPTS_FILE    = $(MATLAB_ROOT)\bin\$(ARCH)\mexopts\msvc110opts.bat
MW_EXTERNLIB_DIR = $(MATLAB_ROOT)\extern\lib\win32\microsoft
MW_LIB_DIR       = $(MATLAB_ROOT)\lib\win32
MEX_ARCH         = -win32
APPVER           = 5.0
CVARSFLAG        = $(cvarsmt)
LIBS_TOOLCHAIN   = $(conlibsmt) libcpmt.lib

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_BIN)
MEX = $(MEX_PATH)\mex

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder Application: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(CVARSFLAG) /wd4996 /fp:precise \
                       /Od /Oy-
CPPFLAGS             = /TP $(cflags) $(CVARSFLAG) /wd4996 /fp:precise /EHsc- \
                       /Od /Oy-
CPP_LDFLAGS          = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
MEX_CFLAGS           = $(MEX_ARCH) OPTIMFLAGS="/Od /Oy- $(MDFLAG) $(DEFINES)" $(MEX_OPTS_FLAG)
MEX_LDFLAGS          = LDFLAGS=='$$LDFLAGS'
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                       -dll -def:$(DEF_FILE)

#--------------------
# File extensions
#--------------------

H_EXT               = .h
OBJ_EXT             = .obj
C_EXT               = .c
EXE_EXT             = .exe
SHAREDLIB_EXT       = .dll
HPP_EXT             = .hpp
OBJ_EXT             = .obj
CPP_EXT             = .cpp
EXE_EXT             = .exe
SHAREDLIB_EXT       = .dll
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw32
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)\sfcndemo_stvdtf.exe
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

#################################################################
# INCLUDE PATHS
#################################################################

INCLUDES_BUILDINFO = $(START_DIR)\sfcndemo_stvdtf_grt_rtw;$(START_DIR);$(MATLAB_ROOT)\toolbox\simulink\simdemos\simfeatures;$(MATLAB_ROOT)\extern\include;$(MATLAB_ROOT)\simulink\include;$(MATLAB_ROOT)\rtw\c\src;$(MATLAB_ROOT)\rtw\c\src\ext_mode\common;$(MATLAB_ROOT)\toolbox\simulink\simdemos\simfeatures\include;$(MATLAB_ROOT)\toolbox\simulink\simdemos\simfeatures\tlc_c

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DMAT_FILE=1 -DINTEGER_CODE=0 -DMT=0 -DCLASSIC_INTERFACE=1 -DONESTEPFCN=0 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0
DEFINES_IMPLIED = -DTID01EQ=1
DEFINES_STANDARD = -DMODEL=sfcndemo_stvdtf -DNUMST=4 -DNCSTATES=0 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\sfcndemo_stvdtf_grt_rtw\rtGetInf.c $(START_DIR)\sfcndemo_stvdtf_grt_rtw\rtGetNaN.c $(START_DIR)\sfcndemo_stvdtf_grt_rtw\rt_nonfinite.c $(START_DIR)\sfcndemo_stvdtf_grt_rtw\sfcndemo_stvdtf.c $(START_DIR)\sfcndemo_stvdtf_grt_rtw\sfcndemo_stvdtf_data.c rt_matrx.c rt_printf.c rt_logging.c rt_sim.c $(MATLAB_ROOT)\rtw\c\grt\classic_main.c $(MATLAB_ROOT)\toolbox\simulink\simdemos\simfeatures\src\stvdtf.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj sfcndemo_stvdtf.obj sfcndemo_stvdtf_data.obj rt_matrx.obj rt_printf.obj rt_logging.obj rt_sim.obj classic_main.obj stvdtf.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) 

CFLAGS = $(CFLAGS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) 

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_BASIC)

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


buildobj : set_environment_variables prebuild $(OBJS) $(PREBUILT_OBJS)
	@cmd /C "@echo ### Successfully generated all binary outputs."


prebuild : 


download : build


execute : download
	@cmd /C "@echo ### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@cmd /C "@echo ### Done invoking postbuild tool."


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	@cmd /C "@echo ### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -out:$(PRODUCT) @$(CMD_FILE) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@cmd /C "@echo ### Created: $(PRODUCT)"
	$(RM) $(CMD_FILE)


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\grt}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\grt}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\simulink\src}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\simulink\simdemos\simfeatures\src}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\simulink\simdemos\simfeatures\src}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\sfcndemo_stvdtf_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\sfcndemo_stvdtf_grt_rtw}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ###  PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ###  PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ###  BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ###  INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ###  DEFINES = $(DEFINES)"
	@cmd /C "@echo ###  ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ###  ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ###  LIBS = $(LIBS)"
	@cmd /C "@echo ###  MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ###  SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ###  TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ###  CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ###  LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ###  SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ###  CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ###  CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ###  CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ###  ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ###  MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ###  MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ###  DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ###  EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ###  MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."

