CFLAGS = -Wall -pedantic -Werror
LFLAGS = `sdl-config --libs` -lSDL -lSDL_image -lSDL_mixer
OBJS   = draw.o init.o input.o graphics.o main.o player.o
PROG = tutorial04
CC = gcc

# top-level rule to create the program.
all: $(PROG)

# compiling other source files.
%.o: src/%.c src/%.h src/defs.h src/structs.h
	$(CC) $(CFLAGS) -c -s $<

# linking the program.
$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG) $(LFLAGS)

# cleaning everything that can be automatically recreated with "make".
clean:
	rm $(PROG) *.o
