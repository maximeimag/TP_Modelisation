SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin


PROG = $(BIN_DIR)/test
OBJS = $(OBJ_DIR)/Dvector.o $(OBJ_DIR)/test.o $(OBJ_DIR)/Height.o $(OBJ_DIR)/WaveModel.o $(OBJ_DIR)/GerstnerWave.o $(OBJ_DIR)/GerstnerWaveModel.o  

CC = clang++
CXXFLAGS = -Wall -g
LDFLAGS = -lm


CPPS = $(SRC_DIR)/Dvector.cpp $(SRC_DIR)/test.cpp

all: $(PROG)

recompile: clean $(PROG)

$(OBJ_DIR)/GerstnerWaveModel.o: $(SRC_DIR)/GerstnerWaveModel.cpp
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/GerstnerWaveModel.cpp -o $(OBJ_DIR)/GerstnerWaveModel.o

$(OBJ_DIR)/WaveModel.o: $(SRC_DIR)/WaveModel.cpp
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/WaveModel.cpp -o $(OBJ_DIR)/WaveModel.o

$(OBJ_DIR)/GerstnerWave.o: $(SRC_DIR)/GerstnerWave.cpp
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/GerstnerWave.cpp -o $(OBJ_DIR)/GerstnerWave.o

$(OBJ_DIR)/Height.o: $(SRC_DIR)/Height.cpp
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/Height.cpp -o $(OBJ_DIR)/Height.o

$(OBJ_DIR)/Dvector.o: $(SRC_DIR)/Dvector.cpp
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/Dvector.cpp -o $(OBJ_DIR)/Dvector.o

$(OBJ_DIR)/test.o: $(SRC_DIR)/test.cpp
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/test.cpp -o $(OBJ_DIR)/test.o



$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(PROG)


.PHONY: clean

clean:
	rm -f $(PROG) $(OBJS)
