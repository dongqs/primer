CC=g++
CFLAGS=-c -std=c++14

all: bin/main
	bin/main

bin/main: obj/main.o obj/str_blob.o obj/str_blob_ptr.o
	$(CC) obj/main.o obj/str_blob.o -o bin/main

obj/main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o obj/main.o

obj/str_blob.o: str_blob.h str_blob.cpp
	$(CC) $(CFLAGS) str_blob.cpp -o obj/str_blob.o

obj/str_blob_ptr.o: str_blob_ptr.h str_blob_ptr.cpp
	$(CC) $(CFLAGS) str_blob_ptr.cpp -o obj/str_blob_ptr.o
