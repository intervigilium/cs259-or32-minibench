# Makefile

CC = or32-elf-gcc
CFLAGS = -O3 -static -mregistermask=0 -mnewlib -mboard=atlys
LIBS =

SRC = crc_32.c
OBJ = ${SRC:.c=.o}
OUT = crc

all: ${OUT}

${OUT}:
	${CC} ${CFLAGS} ${SRC} -o ${OUT} ${LIBS}

.c.o:
	${CC} ${CFLAGS} ${LIBS} -c $< -o $@

clean:
	rm -rf ${OUT} output* *.o
