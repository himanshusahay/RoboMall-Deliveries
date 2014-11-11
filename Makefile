# Makefile

#Author: Himanshu Sahay
CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=hsahay_main.cpp motion.cpp mall.cpp linkedlist.cpp binarytree.cpp eventlist.cpp queue.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE= robotdeliveriesinmall

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
		rm *.o
