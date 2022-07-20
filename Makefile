CC=g++

add-nbo: add-nbo.o meta.o
	$(CC) add-nbo.o meta.o -o add-nbo

add-nbo.o: add-nbo.cpp
	$(CC) -c add-nbo.cpp

meta.o: meta.cpp
	$(CC) -c meta.cpp

clean:
	rm -f add-nbo add-nbo.o meta.o
