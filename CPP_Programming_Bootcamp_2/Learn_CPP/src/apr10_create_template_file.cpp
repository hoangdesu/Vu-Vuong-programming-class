#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;

// run with
// ./createTemplateFile `filename`

int main(int argc, char *argv[]) {
    
    // program arguments: lấy input từ commandline

    // cout << "argument counts: " << argc << endl;

    // cout << argv[0] << endl; // program name + path
    

    if (!argv[1]) {
        std::cerr << "Error: please provide a file name to the command line" << endl;
        return EXIT_FAILURE;
    }

    // cout << argv[1] << endl;

    string filename = argv[1];
    filename += ".cpp";

    if (filesystem::exists(filename)) {
        std::cerr << "Error: File already exists. File was not created" << endl;
        return EXIT_FAILURE;
    }

    ofstream newFile;
    newFile.open(filename);

    cout << "Created file: " << filename << " successfully!" << endl;

    if (!newFile.is_open()) {
        std::cerr << "Error creating new file" << endl;
        return EXIT_FAILURE;
    }

    // write content from a template file to this new file
    ifstream templateFile;
    templateFile.open("template.cpp");

    char c;
    ostringstream content;
    // string content;
    while (templateFile.get(c)){
        // std::cout << c;
        content << c; // stream characters to content stream
        // content += c;
    }

    // cout << content.str() << endl; 

    // write content of template file to new file
    newFile << content.str();


    // close the stream
    newFile.close();
    
    cout << "Successfully written to " << "\"" << filename << "\"" << endl;
    

    return EXIT_SUCCESS;
}
