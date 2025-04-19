#-----------------------COMPILATION------------------------------------------------------
# Compiler and Flags
CC						:= cc
CFLAGS					 = -Wall -Wextra -Werror $(INCLUDES) -g
ADDITIONAL_FLAGS		:= -pthread
INCLUDES				 = $(addprefix -I,$(SRC_DIRS)) $(addprefix -I,$(LIB_DIRS))

#-----------------------BINARIES---------------------------------------------------------
# Output Files
NAME					:= philo

#-----------------------FOLDERS----------------------------------------------------------
# Directories
SRC_DIR					:= src
OBJ_DIR					:= obj
LIB_DIR					:= libraries

# Source directories (src/)
MODEL_DIR				:= $(SRC_DIR)/model
SETUP_DIR				:= $(SRC_DIR)/setup
LOGIC_DIR				:= $(SRC_DIR)/logic
HELPERS_DIR				:= $(SRC_DIR)/helpers
WRAPPERS_DIR			:= $(SRC_DIR)/wrappers

# Logic directories (src/model/)
MONITOR_MODEL_DIR		:= $(MODEL_DIR)/monitor
PHILOSOPHER_MODEL_DIR	:= $(MODEL_DIR)/philosopher
SETTINGS_MODEL_DIR		:= $(MODEL_DIR)/settings
SHARED_MODEL_DIR		:= $(MODEL_DIR)/shared
SIMULATION_MODEL_DIR	:= $(MODEL_DIR)/simulation

# List of all source directories
SRC_DIRS				:= $(SRC_DIR) \
							$(MODEL_DIR) \
							$(SETUP_DIR) \
							$(LOGIC_DIR) \
							$(HELPERS_DIR) \
							$(WRAPPERS_DIR) \
							$(MONITOR_MODEL_DIR) \
							$(PHILOSOPHER_MODEL_DIR) \
							$(SETTINGS_MODEL_DIR) \
							$(SHARED_MODEL_DIR) \
							$(SIMULATION_MODEL_DIR)
							

# Library directories (libraries/)
CIRCULAR_LIST_LIB_DIR	:= $(LIB_DIR)/circular_list

# List of all library directories
LIB_DIRS				:= $(CIRCULAR_LIST_LIB_DIR)

#-----------------------FILES------------------------------------------------------------
# Sources
C_FILES 				:= $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
HEADERS 				:= $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.h))

# Objects
OBJ     				:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(C_FILES)))

#-----------------------LIBRARIES--------------------------------------------------------
# Library files
CIRCULAR_LIST_LIB		:= $(CIRCULAR_LIST_LIB_DIR)/circular_list.a

# Libraries
LIBRARIES				:= $(CIRCULAR_LIST_LIB)

#-----------------------COLORS-----------------------------------------------------------
# Colors for Output
GREEN					:= \033[0;32m
RED						:= \033[31m
RESET					:= \033[0m

#-----------------------RULES------------------------------------------------------------
vpath %c $(SRC_DIRS)
vpath %h $(SRC_DIRS)

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBRARIES)
	@$(CC) $(CFLAGS) $(ADDITIONAL_FLAGS) $^ -o $@
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

#Compile Object Files
$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

%.a:
	@cd $(dir $@); $(MAKE) > /dev/null; $(MAKE) clean > /dev/null
	@# echo "$(GREEN)Compiled $(notdir $@) successfully!$(RESET)"

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removed object files$(RESET)"
	@for lib in $(LIB_DIR)/*/; do \
		$(MAKE) -C $$lib clean > /dev/null; \
	done
	@# echo "$(RED)Removed libraries object files$(RESET)"

# Clean up All Generated Files
fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"
	@for lib in $(LIB_DIR)/*/; do \
		$(MAKE) -C $$lib fclean > /dev/null; \
	done
	@# echo "$(RED)Removed .a libraries$(RESET)"

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re
