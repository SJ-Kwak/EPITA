# Simple Makefile

# Compilers vars
CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra
LDFLAGS=
LDLIBS=

OBJS=test.o is_partition.o
SRC= test.c is_partition.c
DEP= ${SRC:.c=.d}
PRG= ${SRC:.c=}
TARGET=test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^
.c.o:
	$(CC) -c -o $@ $<


-include ${DEP}

clean:
	rm -f *.o
	rm -f ${DEP}
	rm -f ${PRG}

# END Makefile
