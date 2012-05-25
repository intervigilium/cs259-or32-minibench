# Makefile

CC = or32-elf-gcc
CFLAGS = -static -mnewlib -mboard=atlys -DTIMER_HZ=1000
CFLAGS += -DFIB_NUM=25
#CFLAGS += -mregistermask=4294901760
#CFLAGS += -Wa,-mpufkey=0x003ff800
#CFLAGS += -DUSE_SECURE
LIBS =

SRC1 = loop-test.c secure_func.c
OBJ1 = ${SRC1:.c=.o}
OUT1 = loop-test

all: ${OUT1}

${OUT1}:
	${CC} ${CFLAGS} ${SRC1} -o ${OUT1} ${LIBS}

.c.o:
	${CC} ${CFLAGS} ${LIBS} -c $< -o $@

clean:
	rm -rf ${OUT1} output* *.o
