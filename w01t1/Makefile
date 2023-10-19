CC ?= gcc
OPTS = -Ofast -fopenmp

all: main

main:
ifeq ($(findstring login, $(shell hostname)),login)
	@echo "不要在 login 节点编译噢"
	@exit 1
endif
	$(CC) $(OPTS) main.c -o main

.PHONY: clean
clean:
	@rm -f main
