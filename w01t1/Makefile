CC ?= gcc
OPTS = -Ofast -fopenmp

all: main

main:
	$(CC) $(OPTS) main.c -o main

.PHONY: clean
clean:
	@rm -f main
