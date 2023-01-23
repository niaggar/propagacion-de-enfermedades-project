# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
# 'make run'    run your porgram

# define the C compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
#
INCLUDES =

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS =

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname
#   option, something like (this will link in libmylib.so and libm.so:
LIBS =

# define the C source files
SRCS = 	main.cpp ./modules/methods/models/Model.cpp ./modules/methods/models/SirModel.cpp ./modules/methods/models/SirsModel.cpp ./modules/methods/models/SirsVacModel.cpp ./modules/methods/Runge4.cpp ./modules/program/FindMax.cpp ./modules/program/control/Control.cpp ./modules/program/control/ControlFolder.cpp ./modules/program/control/ControlData.cpp ./modules/program/control/ControlProject.cpp ./modules/program/control/ControlReport.cpp ./modules/program/ReadData.cpp ./modules/program/WriteData.cpp ./modules/program/images/Images.cpp ./modules/program/PhaseDiagram.cpp ./modules/program/ContourPlot.cpp

# define the C object files
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

# define the executable file
MAIN = program

# optional arguments to the main program
ARGS =

#
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:    $(MAIN)
				@echo  Simple compiler named mycc has been compiled

$(MAIN): $(OBJS)
				@if [ ! -d "debug" ]; then mkdir debug; fi

				$(CC) $(CFLAGS) $(INCLUDES) -o debug/$(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
.c.o:
				$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
				$(RM) -r *.o *~ ./debug

run:
				./debug/$(MAIN) $(ARGS)

# DO NOT DELETE THIS LINE -- make depend needs it