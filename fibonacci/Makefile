# Makefile

CC = or32-elf-gcc
CFLAGS = -static -mnewlib -mboard=atlys -DTIMER_HZ=1000
#CFLAGS += -mregistermask=4294901760
#CFLAGS += -Wa,-mpufkey=0x003ff800
#CFLAGS += -DUSE_SECURE
LIBS =

SRC1 = fibonacci.c secure_func.c
OBJ1 = ${SRC1:.c=.o}
OUT1 = fibonacci

all: ${OUT1}

${OUT1}:
	${CC} ${CFLAGS} ${SRC1} -o ${OUT1} ${LIBS}

.c.o:
	${CC} ${CFLAGS} ${LIBS} -c $< -o $@

clean:
	rm -rf ${OUT1} output* *.o
