HOME    = $(PWD)
EXEC    = $(HOME)/test
SRC_SCL = $(HOME)/../simple-opencl
CC      = g++
SRC = test.cpp $(SRC_SCL)/simpleCL.cpp
CFLAGS  = -Wall -Wextra -pedantic -O3 -Wno-write-strings

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
INCL_P  = -I$(HOME)/inc -I/usr/local/cuda/include
LIBS   = -lm -lOpenCL -lrt
INCL_AMD = -I$(HOME)/inc -I/opt/AMDAPP/include
LIBS_AMD = -L/opt/AMDAPP/lib/x86_64 $(LIBS)
CFLAGS_AMD  = $(CFLAGS) -DATI_OS_LINUX
endif
ifeq ($(UNAME), Darwin)
INCL_P   = -I$(HOME)/inc
LIBS     = -framework OpenCL
INCL_AMD = $(INCL_P)
LIBS_AMD = $(LIBS)
CFLAGS_AMD = $(CFLAGS)
endif

all:
	$(CC) $(CFLAGS) $(INCL_P) -c $(SRC)
	$(CC) $(CFLAGS) *.o -o $(EXEC) $(LIBS)
	rm -f *.o

amd:

	$(CC) $(CFLAGS_AMD) -c $(SRC) $(INCL_AMD)
	$(CC) $(CFLAGS) *.o -o $(EXEC) $(LIBS_AMD)
	rm -f *.o

clean:
	rm -f *.o $(EXEC)

cleanbin:
	rm -f snapshot* image*
