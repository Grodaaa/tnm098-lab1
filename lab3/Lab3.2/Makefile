# Select appropriate compiler.
#CPP=gcc
#CPP=g++
#CPP=clang++
#CPPFLAGS=-O3 -fopenmp       
# Use this for gcc >= 4.2
#CPPFLAGS=-O3               # Use this for gcc <  4.2
CC = g++
CPPFLAGS=-O3

ifdef DEBUG
CPPFLAGS=-g
endif

MKDIR = mkdir -p bin
LIBFOLD = -L"/usr/local/lib"
INCFOLD = -I"/usr/local/include"

BINFOLD = bin/

FRAMEWORKS = -framework OpenGL -std=c++11

BINNAME = main

FILES = $(wildcard src/*.cpp)

#default: all

all: compile

compile: $(FILES)
	$(CC) $(CPPFLAGS) $(FILES) -o $(BINFOLD)$(BINNAME) $(LIBFOLD) $(INCFOLD) $(FRAMEWORKS)
.PHONY: all

run:
	./$(BINFOLD)$(BINNAME)
.PHONY: run

clean:
	rm -f *.o main