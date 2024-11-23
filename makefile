OBJ:= $(patsubst %.c, %.o, $(wildcard *.c))
calc.out: $(OBJ)
	gcc -o $@ $^  
clean:
	rm *.o