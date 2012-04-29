#for GNU make

#DDEBUG = -O0 -g -ggdb -DDEBUG=1

#CC = gcc46 -Wall -O3 -std=c99 -Wmissing-prototypes $(DDEBUG)
CC = gcc -Wall -O3 -std=c99 -Wmissing-prototypes $(DDEBUG)
#CC = icc -Wall -O3 -std=c99 -Wmissing-prototypes $(DDEBUG)

all:  check32 check64 dump32 byarray32

check32:  check32.c tinymt32.o
	${CC} -o $@  check32.c tinymt32.o ${LINKOPT}

check64:  check64.c tinymt64.o
	${CC} -o $@  check64.c tinymt64.o ${LINKOPT}

dump32:  dump32.c tinymt32.o
	${CC} -o $@  dump32.c tinymt32.o ${LINKOPT}

byarray32:  byarray32.c tinymt32.o
	${CC} -o $@  byarray32.c tinymt32.o ${LINKOPT}

doc: doxygen.cfg tinymt32.c tinymt64.c tinymt32.h tinymt64.h mainpage.txt
	doxygen doxygen.cfg

.c.o:
	${CC} -c $<

clean:
	rm -rf *.o *~ *.dSYM html
