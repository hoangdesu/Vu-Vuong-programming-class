.default: all

all: main

clean:
	rm -f main

# mazeRunner:
# 	g++ -Wall -Werror -std=c++17 -g -O -o $@  -lmcpp


main: clean
	g++ -Wall -Werror -std=c++17 -g -O -I mcpp/include -o main main.cpp mcpp/src/*.cpp
	./main


# %.o: %.cpp
# 	g++ -Wall -Werror -std=c++17 -g -O -c $^