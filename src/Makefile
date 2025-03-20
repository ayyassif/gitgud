# colors
RED=\033[0;31m
ORANGE=\033[0;33m
YELLOW=\033[1;33m
GREEN=\033[0;32m
BLUE=\033[0;34m
INDIGO=\033[0;35m
VIOLET=\033[1;35m
RESET=\033[0m

CC = gcc

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

TARGET = gitgud

all: print $(TARGET)

print:
	@echo -e "$(RED)╭────────────────────────────────────╮$(RESET)"
	@echo -e "$(RED)│$(GREEN)             __                  __ $(RED)│$(RESET)"
	@echo -e "$(RED)│$(GREEN)    ____ _(_) /_____ ___  ______/ / $(RED)│$(RESET)"
	@echo -e "$(RED)│$(GREEN)   / __  / / __/ __  / / / / __  /  $(RED)│$(RESET)"
	@echo -e "$(RED)│$(GREEN)  / /_/ / / /_/ /_/ / /_/ / /_/ /   $(RED)│$(RESET)"
	@echo -e "$(RED)│$(GREEN)  \__, /_/\__/\__, /\__,_/\__,_/    $(RED)│$(RESET)"
	@echo -e "$(RED)│$(GREEN) /____/      /____/                 $(RED)│$(RESET)"
	@echo -e "$(RED)╰────────────────────────────────────╯$(RESET)"

$(TARGET): $(OBJ)
	@echo -e "$(YELLOW)[Building the project...]$(RESET)"
	@$(CC) $(OBJ) -o $(TARGET)
	@echo -e "$(YELLOW)[Compiling source files...]$(RESET)"
	@echo -e "$(BLUE)[Cleaning up object files...]$(RESET)"
	@rm -rf *.o
	@echo -e "$(GREEN)[Static library has been compiled!]$(RESET)"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean: print
	@echo -e "$(BLUE)[Cleaning...]$(RESET)"
	@rm -rf *.o
	@echo -e "$(GREEN)[Project has been cleaned!]$(RESET)"

re: clean all

.PHONY: all print clean re