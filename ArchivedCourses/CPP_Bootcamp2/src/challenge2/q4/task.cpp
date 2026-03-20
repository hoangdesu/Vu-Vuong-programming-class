#include <iostream>
#include "task.h"

using namespace std;

LogSanitizer::LogSanitizer(const char* inputLog) {
    for (int i = 0; i < 100; i++) {
        sanitizedLog[i] = inputLog[i];
    }
}

// TODO: fix return type
const char* LogSanitizer::sanitizeLog() {
    for (int i = 0; i < 100; i++) {
        if (sanitizedLog[i] >= '0' && sanitizedLog[i] <= '9') {
            sanitizedLog[i] = '!';
        } else if (sanitizedLog[i] == 'a' || sanitizedLog[i] == 'i' || sanitizedLog[i] == 'u' || sanitizedLog[i] == 'e' || sanitizedLog[i] == 'o') {
            sanitizedLog[i] = '*';
        }
    }

    char *s;
    return s;
}

// TODO: fix return type
const char* LogSanitizer::getSanitizedLog() const {
    string s = "";
    for (int i = 0; sanitizedLog[i] != '\0'; i++) {
        s += sanitizedLog[i];
    }

    cout << s << endl;

    char* c = nullptr;
    return c;
}