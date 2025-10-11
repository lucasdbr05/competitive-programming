CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Wshadow -Wconversion -Wno-unused-result

SRC ?= main.cpp
OUT := out

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

runin: all
	./$(OUT) < in.txt

clean:
	rm -f $(OUT)
copy:
	cp temp.cpp main.cpp