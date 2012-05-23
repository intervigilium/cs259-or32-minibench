# Makefile

CC = or32-elf-gcc
CFLAGS = -static -mnewlib -mboard=atlys
#CFLAGS += -O3 -mregistermask=4294901760
#CFLAGS += -Wa,-mpufkey=0x003ff800
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
