CC= gcc
OBJS= functions.o Program.o exe.o functions2.o
EXEC= assignment
DEBUG= -g
CFLAGS= -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) :$(OBJS)
	$(CC) $(OBJS) -o $@

exe.o: exe.c exe.h functions.h functions2.h
functions2.o: functions2.c functions2.h
functions.o: functions.c functions.h
Program.o: Program.c exe.h


clean:
	rm -f $(EXEC) $(OBJS)
