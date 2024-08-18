# Diretórios
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INC_DIR := include

# Nome do executável
TARGET := pa2.out

# Compilador e flags
CXX := g++
CXXFLAGS := -I$(INC_DIR) -Wall -Wextra -O2

# Lista de arquivos fonte
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# Lista de arquivos objeto
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Regras padrão
all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
