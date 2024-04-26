CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iheaders
TARGET = main
SRC = src/main.cpp src/Graph.cpp src/Node.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
