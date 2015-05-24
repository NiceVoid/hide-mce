CFLAGS += -W
CFLAGS += -Wall
CFLAGS += -mwindows
CROSS = i686-w64-mingw32-
CC = $(CROSS)gcc
STRIP = $(CROSS)strip

all: hide-mse.exe
	$(STRIP) hide-mse.exe

hide-mse.exe: src/hide-mse.c
	$(CC) $(CFLAGS) -o $@ $^
