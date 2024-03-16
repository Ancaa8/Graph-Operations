.PHONY: build clean

build: Heap.o Graph.o
	gcc main.c Heap.o Graph.o -o tema3

Heap.o:
	gcc Heap.c -c

Graph.o: Heap.o
	gcc Graph.c -c

clean:
	rm tema3 *.o