KERN=gemm
#CFLAGS?=-O3 -Wall
CFLAGS?=-pg -O3 -Wall 
CC = gcc


SRCS=$(KERN).c main.c
FILES=$(SRCS) $(KERN).h

$(KERN): $(FILES)
	$(CC) $(CFLAGS) -o $(KERN) $(SRCS)

run: $(KERN) 
	./$(KERN)
clean:
	rm -f $(KERN) output.data gmon.out
