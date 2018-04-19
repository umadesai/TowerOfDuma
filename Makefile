CXX = g++
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
APP = game
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) # get all .c files in the SRC_DIR
# create corresponding object files list
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS = -g -Wall -Wextra -pedantic -ansi -std=c++0x

# all, directories are not actually files we will create
.PHONY: all directories


all: directories $(APP)

# link OBJECTS to the APP executable
$(APP): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

directories:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)
	rm -f $(APP)
