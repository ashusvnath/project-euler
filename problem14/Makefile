SRC_C = problem14.c problem14_tree_mod.c problem14_stack_mod.c
SRC_H = problem14.h
OBJS = $(SRC_C:.c=.o)
CFLAGS = -g -O0

.PHONY: all run clean

all: problem14 run

problem14: $(OBJS)
	cc -o problem14 -g $(OBJS)

run:  
	./problem14

clean:
	rm -f $(OBJS)

$(OBJS): $(SRC_H) $(SRC_C)
