.default: all

all: gen-village

clean:
	rm -f gen-village *.o

gen-village: main.o task_a.o task_b.o task_c.o
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^ -lmcpp

%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -g -O -c $^

tasks: main.cpp task_a.cpp task_b.cpp task_c.cpp
	@echo "Compiling Tasks..."
	g++ -std=c++17 -Wall -o tasks main.cpp task_a.cpp task_b.cpp task_c.cpp plots.cpp -I. -pthread -lmcpp
	@echo "Build complete! Run with ./tasks"
