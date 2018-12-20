CFLAGS=-g -O2 -Wall
CC=gcc

PROGRAM_NAME= evolve
OBJS = main.o readwriteppm.o fitness.o population.o evolve.o \
	crossover.o mutate.o

$(PROGRAM_NAME): $(OBJS)
	$(CC) -o $@ $? -lm

clean:
	rm  *.o $(PROGRAM_NAME) 
