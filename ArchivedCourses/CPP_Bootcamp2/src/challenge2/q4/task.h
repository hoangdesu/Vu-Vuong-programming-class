#ifndef LOGSANITIZER_H
#define LOGSANITIZER_H

using namespace std;

class LogSanitizer {
    private:
    char sanitizedLog[100];   

    public:
    LogSanitizer(const char* inputLog);
    const char* sanitizeLog();
    const char* getSanitizedLog() const;
};

#endif
