#include <iostream>
#include <cstring>

using namespace std;

string print_str(char str[], char delim, int N) {
    // cout << str;
    
    // for (int i = 0 ; str[i] != '\0'; i++) {
    //     cout << i << str[i] << endl;
    // }

    int i = 0;
    int j = i+1;

    string words[20];
    int wordIndex = 0;

    while (str[i] != '\0') {
        while (str[j] != delim && str[j] != '\0') {
            j++;
        }

        // build string from i to j-1
        char* substr = new char[30];
        int substrIndex = 0;
        for (int a = i; a < j; a++) {
            // cout << str[a];
            substr[substrIndex] = str[a];
            substrIndex++;
        }
        
        words[wordIndex] = substr;
        wordIndex++;

        cout << "substring: " << substr << endl;
        delete[] substr;

        i = j+1;
        j = i+1;
    }

    // cout << "words[N-1]: " << words[N-1];

    return words[N-1];
}

int main(void) {

    char str[100] = "This,is,a,test,string"; // '\0';

    char delim;
    int N; 
    // cin >> delim;
    // cin >> N;

    delim = ',';
    N = 3;


    // cout << delim << N;

    // cout << str << endl;

    // cout << "function: " << endl;

    int len = sizeof(str) / sizeof(str[0]);
    // cout << "len = " << len << endl;
    
    string token = print_str(str, delim, N);
    cout << "Token: " << token << endl;

    return 0;
}