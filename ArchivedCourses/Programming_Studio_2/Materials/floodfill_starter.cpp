#include <iostream>
#include <vector>

class Coord {
    public:
        int r ;
        int c ;
        Coord(int r, int c) {
            this->r = r ;
            this->c = c ;
        }

        friend Coord operator+(Coord& lhs, Coord& rhs) {
            Coord c(lhs.r+rhs.r, lhs.c+rhs.c) ;
            return c ;
        }
};


void readEnv(char **& env, int& height, int& width) ;
void printEnv(char ** env, int height, int width) ;

void floodFill(char **& env, int& height, int& width, Coord& curr) ;

int main() {
    char ** env ;
    int height ;
    int width ;

    readEnv(env, height, width) ;
    printEnv(env, height, width) ;

    Coord start(1, 1) ;

    floodFill(env, height, width, start) ;

    return 0;
}


void readEnv(char**& env, int& height, int& width) {
    char c ;
    std::cout << "Height: " ;
    std::cin >> height ;
    std::cout << "Width: " ;
    std::cin >> width ;

    std::cout << "Env: " << std::endl ;
    env = new char * [height] ;
    for (int i = 0 ; i < height ; i++ ) {
        env[i] = new char [width] ;
        for(int j = 0 ; j < width ; j++ ) {
            std::cin >> c ;
            env[i][j] = c ;
        }
    }
    std::cout << std::endl ;

    return ;
}


void printEnv(char ** env, int height, int width) {
    for (int i = 0 ; i < height ; i++ ) {
        for(int j = 0 ; j < width ; j++ ) {
            std::cout << env[i][j] << ' ' ;
        }
        std::cout << std::endl ;
    }
}



void floodFill(char **& env, int& height, int& width, Coord& curr) {

}