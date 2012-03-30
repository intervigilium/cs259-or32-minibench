# Makefile

CC = or32-elf-gcc
CFLAGS = -O3 -static -mregistermask=4294901760 -mnewlib -mboard=atlys
LIBS =

SRC1 = bmhasrch.c bmhisrch.c bmhsrch.c pbmsrch_small.c
OBJ1 = ${SRC1:.c=.o}
OUT1 = search_small

SRC2 = bmhasrch.c bmhisrch.c bmhsrch.c pbmsrch_large.c
OBJ2 = ${SRC2:.c=.o}
OUT2 = search_large

all: ${OUT1} ${OUT2}

${OUT1}:
	${CC} ${CFLAGS} ${SRC1} -o ${OUT1} ${LIBS}

${OUT2}:
	${CC} ${CFLAGS} ${SRC2} -o ${OUT2} ${LIBS}

.c.o:
	${CC} ${CFLAGS} ${LIBS} -c $< -o $@

clean:
	rm -rf ${OUT1} ${OUT2} output* *.o
