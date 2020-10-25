CFLAGS = -Wall -pedantic -Werror
LFLAGS = `sdl-config --libs` -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
OBJS   = audio.o animation.o bullet.o collisions.o draw.o entity.o font.o init.o input.o graphics.o main.o player.o rock.o stars.o
PROG = tutorial10
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
