CC= gcc
OBJS= functions.o Program.o exe.o
EXEC= assignment
DEBUG= -g
CFLAGS= -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) :$(OBJS)
	$(CC) $(OBJS) -o $@

arrays.o: arrays.c
exe.o: exe.c exe.h functions.h
functions.o: functions.c functions.h
Program.o: Program.c exe.h


clean:
	rm -f $(EXEC) $(OBJS)
