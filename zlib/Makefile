# Makefile

CC = or32-elf-gcc
CFLAGS = -static -Os -mregistermask=4294901760 -mnewlib -mboard=atlys
LIBS =

SRC = zlib_bench.c deflate.c zutil.c crc32.c adler32.c gzlib.c gzflags.c trees.c
OBJ = ${SRC:.c=.o}
OUT = zlib_bench

all: ${OUT}

${OUT}:
	${CC} ${CFLAGS} ${SRC} -o ${OUT} ${LIBS}

.c.o:
	${CC} ${CFLAGS} ${LIBS} -c $< -o $@

clean:
	rm -rf ${OUT} output* *.o
