# Makefile

CC = or32-elf-gcc
CFLAGS = -static -O3 -mregistermask=0 -mnewlib -mboard=atlys
LIBS= -lm

SRC = fftmisc.c fourierf.c
OBJ = ${SRC:.c=.o}
OUT = fft

all: ${OUT}

${OUT}: ${OBJ}
	${CC} ${CFLAGS} main.c ${OBJ} -o ${OUT} ${LIBS}

.c.o:
	${CC} ${CFLAGS} ${LIBS} -c $< -o $@

clean:
	rm -rf ${OUT} output* *.o
