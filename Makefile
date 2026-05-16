CXX = g++
CXXFLAGS = -Wall -std=c++20

SRC = main.cpp server.cpp parser.cpp store.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = redix

$(TARGET): $(OBJ)
	g++ $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)