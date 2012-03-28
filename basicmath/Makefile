# Makefile

CC = or32-elf-gcc
CFLAGS = -static -O3 -mregistermask=0 -mnewlib
LIBS = -lm

SRC1 = basicmath_small.c rad2deg.c cubic.c isqrt.c
OBJ1 = ${SRC1:.c=.o}
OUT1 = basicmath_small

SRC2 = basicmath_large.c rad2deg.c cubic.c isqrt.c
OBJ2 = ${SRC2:.c=.o}
OUT2 = basicmath_large

all: ${OUT1} ${OUT2}

${OUT1}:
	${CC} ${CFLAGS} ${SRC1} -o ${OUT1} ${LIBS}
${OUT2}:
	${CC} ${CFLAGS} ${SRC2} -o ${OUT2} ${LIBS}

.c.o:
	${CC} ${CFLAGS} ${LIBS} -c $< -o $@

clean:
	rm -rf ${OUT1} ${OUT2} output* *.o
