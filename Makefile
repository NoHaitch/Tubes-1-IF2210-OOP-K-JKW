# Code Compiler
CC=g++

# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin
OBJ_PATH = $(OUTPUT_FOLDER)/o

# Files
HEADER_FILES = $(wildcard $(SOURCE_FOLDER)/header/*.hpp)
OBJ_FILES = $(patsubst $(SOURCE_FOLDER)/%.cpp,$(OBJ_PATH)/%.o,$(CPP_FILES))
CPP_FILES = $(wildcard $(SOURCE_FOLDER)/**/*.cpp $(SOURCE_FOLDER)/*.cpp)

# Main Commands
all: build run

run: 
	./$(OUTPUT_FOLDER)/main

build: $(OBJ_FILES)
	$(CC) $^ -o $(OUTPUT_FOLDER)/main

clean:
	rm -rf $(filter-out $(OUTPUT_FOLDER), $(wildcard $(OUTPUT_FOLDER)/*))

# Rule to compile object files
$(OBJ_PATH)/%.o: $(SOURCE_FOLDER)/%.cpp $(HEADER_FILES)
	@mkdir -p $(@D)
	$(CC) -c $< -o $@