#include <iostream> // standard console stream
#include <fstream> // file IO stream
#include <string>

using namespace std;

int main() {
    string fname = "Vuong";
    string lname = "Nguyen";

    cout << fname << " " << lname << endl;
    cout << fname + " " + lname << endl;

    string filename = "test_file2.txt";
    std::ofstream myFile; // ofstream = output file stream
    // myFile.open(filename); // normal mode: overwrite existing file
    myFile.open("testfile3.txt", ofstream::app); // append mode

    // outFile << fname << " " << lname << endl;
    myFile << "hehe =))" << endl;
    myFile.close(); // remember to close file after writing

    ifstream fileToRead;
    fileToRead.open("hola.cpp");
    // fileToRead.

    string content = "";
    string line;
    while (std::getline(fileToRead, line)) {
        cout << line << endl;
    }

    std::string word;
    while(fileToRead >> word) {
        cout << word << endl;
    }

    // HW:
    // input first name and last name
    // write to a write with a counter 100 times
    
    // Vuong
    // Nguyen

    // 1. Vuong Nguyen
    // 2. Vuong Nguyen

    return EXIT_SUCCESS;
}