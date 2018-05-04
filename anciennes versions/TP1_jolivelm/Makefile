SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin


PROG = $(BIN_DIR)/test
OBJS = $(OBJ_DIR)/Dvector.o $(OBJ_DIR)/test.o

CC = clang++
CXXFLAGS = -Wall -g
LDFLAGS = -lm


CPPS = $(SRC_DIR)/Dvector.cpp $(SRC_DIR)/test.cpp

all: $(PROG)

$(OBJ_DIR)/Dvector.o: $(SRC_DIR)/Dvector.cpp
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/Dvector.cpp -o $(OBJ_DIR)/Dvector.o

$(OBJ_DIR)/test.o: $(SRC_DIR)/test.cpp
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/test.cpp -o $(OBJ_DIR)/test.o

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(PROG)


.PHONY: clean

clean:
	rm -f $(PROG) $(OBJS)
