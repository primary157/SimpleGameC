CC=gcc -std=c11
EXEC=main
OBJ=main.o MeuPoder.o
all: $(EXEC)
$(EXEC): $(OBJ)
	$(CC) -o $@ $^
%.o: %.c
	$(CC) -c $^ $(CFLAGS)
.PHONY: clean mrproper
clean:
	rm -rf $(OBJ)
mrproper: clean
	rm -rf $(EXEC)
