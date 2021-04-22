EXEC = dijkstra
CC = g++ 
CFLAGS = -c 
# $(EXEC) has the value of shell variable EXEC, which is run. CC = g++ -04 CFLAGS = -c -Wall
# run depends on the files main.o util.o heap.o
$(EXEC) :main.o util.o heap.o graph.o
# run is created by the command g++ -o run main.o util.o
# note that the TAB before $(CC) is REQUIRED...
		$(CC) -o $(EXEC) main.o util.o heap.o graph.o
# main.o depends on the files main.h main.cpp
Main.o : main.cpp util.h heap.h graph.h 
# main.o is created by the command g++ -c -Wall main.cpp
# note that the TAB before $(CC) is REQUIRED...
		$(CC) $(CFLAGS) main.cpp
Util.o : util.h util.cpp
		$(CC) $(CFLAGS) util.cpp
Heap.o : heap.h heap.cpp
		$(CC) $(CFLAGS) heap.cpp
Graph.o : graph.h graph.cpp
		$(CC) $(CFLAGS) graph.cpp


clean :
		rm *.o
