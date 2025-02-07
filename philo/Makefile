# Compiler and Flags
CC						:= cc
CFLAGS					 = -Wall -Wextra -Werror $(INCLUDES) -g
ADDITIONAL_FLAGS		:= -pthread

# Output Files
NAME					:= philo

# Directories
SRC_DIR					:= src
MODEL_DIR				:= $(SRC_DIR)/model
SETUP_DIR				:= $(SRC_DIR)/setup
LOGIC_DIR				:= $(SRC_DIR)/logic
HELPERS_DIR				:= $(SRC_DIR)/helpers
WRAPPERS_DIR			:= $(SRC_DIR)/wrappers
OBJ_DIR					:= obj
LIBRARIES_DIR			:= libraries
CIRCULAR_LIST_LIB_DIR	:= $(LIBRARIES_DIR)/circular_list

# Includes
INCLUDES				:= -I$(SRC_DIR) \
							-I$(MODEL_DIR) \
							-I$(SETUP_DIR) \
							-I$(LOGIC_DIR) \
							-I$(HELPERS_DIR) \
							-I$(WRAPPERS_DIR) \
							-I$(CIRCULAR_LIST_LIB_DIR)

# Files
FILES					:= $(notdir $(wildcard $(SRC_DIR)/*.c)) \
							$(notdir $(wildcard $(MODEL_DIR)/*.c)) \
							$(notdir $(wildcard $(SETUP_DIR)/*.c)) \
							$(notdir $(wildcard $(LOGIC_DIR)/*.c)) \
							$(notdir $(wildcard $(HELPERS_DIR)/*.c)) \
							$(notdir $(wildcard $(WRAPPERS_DIR)/*.c)) \

# Objects
OBJ     				:= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# Libraries
CIRCULAR_LIST_LIB		:= $(CIRCULAR_LIST_LIB_DIR)/circular_list.a

# Libraries sum up
LIBRARIES				:= $(CIRCULAR_LIST_LIB)

# Colors for Output
GREEN					:= \033[0;32m
RED						:= \033[31m
RESET					:= \033[0m

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBRARIES)
	@$(CC) $(CFLAGS) $(ADDITIONAL_FLAGS) $^ -o $@
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

#Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(MODEL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SETUP_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LOGIC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(HELPERS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(WRAPPERS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

%.a:
	@cd $(dir $@); $(MAKE) > /dev/null; $(MAKE) clean > /dev/null
	@# echo "$(GREEN)Compiled $(notdir $@) successfully!$(RESET)"

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removed object files$(RESET)"
	@for lib in $(LIBRARIES_DIR)/*/; do \
		$(MAKE) -C $$lib clean > /dev/null; \
	done
	@# echo "$(RED)Removed libraries object files$(RESET)"

# Clean up All Generated Files
fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"
	@for lib in $(LIBRARIES_DIR)/*/; do \
		$(MAKE) -C $$lib fclean > /dev/null; \
	done
	@# echo "$(RED)Removed .a libraries$(RESET)"

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re
