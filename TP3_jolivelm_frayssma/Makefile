SRC_DIR = src
TEST_DIR = test
OBJ_DIR = obj
BIN_DIR = bin


PROG = $(BIN_DIR)/test $(BIN_DIR)/test_methodes_Dvector $(BIN_DIR)/Ocean
OBJS_TEST = $(OBJ_DIR)/Dvector.o $(OBJ_DIR)/test.o $(OBJ_DIR)/Height.o $(OBJ_DIR)/WaveModel.o $(OBJ_DIR)/GerstnerWave.o $(OBJ_DIR)/GerstnerWaveModel.o  $(OBJ_DIR)/PhilipsWaveModel.o
OBJS_MAIN = $(OBJ_DIR)/Dvector.o $(OBJ_DIR)/Height.o $(OBJ_DIR)/WaveModel.o $(OBJ_DIR)/GerstnerWave.o $(OBJ_DIR)/GerstnerWaveModel.o  $(OBJ_DIR)/PhilipsWaveModel.o $(OBJ_DIR)/main.o $(OBJ_DIR)/camera.o $(OBJ_DIR)/ocean.o $(OBJ_DIR)/window.o
TEST_1 = $(OBJ_DIR)/Dvector.o $(OBJ_DIR)/test_methodes_Dvector.o $(OBJ_DIR)/Height.o $(OBJ_DIR)/WaveModel.o $(OBJ_DIR)/GerstnerWave.o $(OBJ_DIR)/GerstnerWaveModel.o  $(OBJ_DIR)/PhilipsWaveModel.o

CC = clang++
CXXFLAGS = -Wall -g
LDFLAGS = -lm


CPPS = $(SRC_DIR)/Dvector.cpp $(SRC_DIR)/test.cpp

all: $(PROG)

recompile: clean $(PROG)

$(OBJ_DIR)/PhilipsWaveModel.o: $(SRC_DIR)/PhilipsWaveModel.cpp
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/PhilipsWaveModel.cpp -o $(OBJ_DIR)/PhilipsWaveModel.o

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

$(OBJ_DIR)/test_methodes_Dvector.o: $(TEST_DIR)/test_methodes_Dvector.cpp
	$(CC) $(CXXFLAGS) $(INCS) -c $(TEST_DIR)/test_methodes_Dvector.cpp -o $(OBJ_DIR)/test_methodes_Dvector.o



$(OBJ_DIR)/camera.o: $(SRC_DIR)/camera.cxx
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/camera.cxx -o $(OBJ_DIR)/camera.o

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cxx
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/main.cxx -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/ocean.o: $(SRC_DIR)/ocean.cxx
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/ocean.cxx -o $(OBJ_DIR)/ocean.o

$(OBJ_DIR)/window.o: $(SRC_DIR)/window.cxx
	$(CC) $(CXXFLAGS) $(INCS) -c $(SRC_DIR)/window.cxx -o $(OBJ_DIR)/window.o



$(BIN_DIR)/test: $(OBJS_TEST)
	$(CC) $(LDFLAGS) $(OBJS_TEST) -o $(BIN_DIR)/test

$(BIN_DIR)/test_methodes_Dvector: $(TEST_1)
	$(CC) $(LDFLAGS) $(TEST_1) -o $(BIN_DIR)/test_methodes_Dvector

$(BIN_DIR)/Ocean: $(OBJS_MAIN)
	$(CC) $(LDFLAGS) $(OBJS_MAIN) -o $(BIN_DIR)/test_methodes_Dvector


.PHONY: clean

clean:
	rm -f $(PROG) $(OBJS)
