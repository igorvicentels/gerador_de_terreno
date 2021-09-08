all: terrain.c funcs io
  gcc terrain.c funcs.o io.o -o terrain -g -W -pedantic
funcs: funcs.c
  gcc funcs.c -c -g -W -pedantic
io: io.c
  gcc io.c -c -g -W -pedantic