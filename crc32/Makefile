# Makefile

CC = or32-elf-gcc
CFLAGS = -static -mnewlib -mboard=atlys -DTIMER_HZ=1000
#CFLAGS += -mregistermask=4294901760
#CFLAGS += -Wa,-mpufkey=0x003ff800
#CFLAGS += -DUSE_SECURE
LIBS =

SRC = crc32.c main.c secure_func.c
OBJ = ${SRC:.c=.o}
OUT = crc

all: ${OUT}

${OUT}:
	${CC} ${CFLAGS} ${SRC} -o ${OUT} ${LIBS}

.c.o:
	${CC} ${CFLAGS} ${LIBS} -c $< -o $@

clean:
	rm -rf ${OUT} output* *.o
