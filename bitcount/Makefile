# Makefile

CC = or32-elf-gcc
CFLAGS = -static -O3 -mregistermask=0 -mnewlib -mboard=atlys
LIBS =

SRC = bitcnt_1.c bitcnt_2.c bitcnt_3.c bitcnt_4.c bitcnts.c bitfiles.c bitstrng.c bstr_i.c
OBJ = ${SRC:.c=.o}
OUT = bitcnts

all: ${OUT}

${OUT}:
	${CC} ${CFLAGS} ${SRC} -o ${OUT} ${LIBS}

.c.o:
	${CC} ${CFLAGS} ${LIBS} -c $< -o $@

clean:
	rm -rf ${OUT} output* *.o
