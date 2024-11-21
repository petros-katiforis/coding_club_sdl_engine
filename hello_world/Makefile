# Returns all c files nested or not in $(1)
define collect_sources
	$(shell find $(1) -name '*.c')
endef

# Modify these variables to apply your preferences
OBJ_DIR := objects
EXE_NAME := bin

SOURCES := $(call collect_sources, src)
OBJECTS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Make sure it is already installed! Consult your package manager
LIBRARIES := sdl2 SDL2_image
C_FLAGS := `pkg-config --cflags $(LIBRARIES)`
L_FLAGS := `pkg-config --libs $(LIBRARIES)` -lm

# Custom targets that do not correspond to real files
.PHONY: run clean

run: $(EXE_NAME)
	@# Executing the program once it has successfully been built
	@./$(EXE_NAME)

$(EXE_NAME): $(OBJECTS)
	@# Lines prefixed with @ will not be displayed in the output of the `make` command
	@# Note however that *their* output, will
	@echo "{Makefile} Creating the executable"
	@$(CC) $(OBJECTS) -o $(EXE_NAME) $(L_FLAGS)

objects/%.o: %.c
	@# Making sure that the directory already exists before creating the object
	@# man mkdir!
	@mkdir -p $(dir $@)

	@echo "{Makefile} Building $@"
	$(CC) -c $< -o $@ $(C_FLAGS)

# Can be called to destroy all build files
# A clean build might rarely result in a bug fix
clean:
	rm -rf $(OBJ_DIR) # OBJ_DIR != / O_O
	rm $(EXE_NAME)
