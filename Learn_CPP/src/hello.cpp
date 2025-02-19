#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<string> msg {"Hello", "World"};
    
    std::cout << "Hello C++" << endl;

    for (const string& word : msg)
    {
        cout << word << " - ";
    }

    // cout << endl;
    
    return 0;
}