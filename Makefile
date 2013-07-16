CXX=g++
CXXFLAGS=-Wall -Wextra -Weffc++ -pedantic -O2
CXXLIBS=-lsfml-window -lsfml-graphics -lsfml-system
OBJS=main.o MainWindow.o GameArea.o tools.o
TARGET=rec-tictactoe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAFS) $^ $(CXXLIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
