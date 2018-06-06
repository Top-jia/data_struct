all:main

main:main.o static_list_table.o
	g++ -o main main.o static_list_table.o
main.o:main.cpp
	g++ -c main.cpp -g
static_list_table.o:static_list_table.cpp
	g++ -c static_list_table.cpp -g
run:
	./main
Debug:
	valgrind --tool=memcheck ./main
clear:
	rm -rf *.o && rm -rf main
