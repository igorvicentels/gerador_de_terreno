PARAMS = -g -std=c99 -Wall -Wextra -Werror -pedantic
 
all: terrain.c funcs io
	gcc terrain.c funcs.o io.o -o final $(PARAMS)
funcs: funcs.c
	gcc funcs.c -c $(PARAMS)
io: io.c
	gcc io.c -c $(PARAMS)