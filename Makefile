EXEC= tst
CC= gcc
FLAGS= -g

all: $(EXEC) 
$(EXEC) : mem.h mem.c test.c consoleout.h
	$(CC) $(FLAGS) -o $(EXEC) mem.c mem.h test.c consoleout.h
clean :
	rm -f tst 