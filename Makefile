CC   		=    gcc

CFLAGS    	=    -W -Wall -Wextra -I./include

SRC    		=    $(wildcard src/*.c)

OBJ    		=    $(SRC:.c=.o)

BIN    		=    garbage_collector

all: $(OBJ)
	@$(CC) $(OBJ) -o $(BIN)
	@echo "Build OK"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(BIN)

re: fclean all