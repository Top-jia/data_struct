all:main

#Which compiler
CC = g++

#Where are include file kept
INCLUDE = .

#Option for development
CFLAGS	=g 

#Debug
DEBUG	= gdb

#Valgrind
MCHECK	= valgrind --tool=memcheck 

#Funtion called process
Strace	= strace 


main: main.o single_list_table.o
	$(CC) -o main main.o single_list_table.o

main.o: main.cpp
	$(CC) -c main.cpp -$(CFLAGS) -l$(INCLUDE)

single_list_table.o: single_list_table.cpp
	$(CC) -c single_list_table.cpp -$(CFLAGS) -l$(INCLUDE)

run:
	./main
debug:
	$(DEBUG) main
strace:
	$(Strace) -p main
mcheck:
	$(MCHECK) ./main

clean:
	rm -rf *.o && rm -rf main
