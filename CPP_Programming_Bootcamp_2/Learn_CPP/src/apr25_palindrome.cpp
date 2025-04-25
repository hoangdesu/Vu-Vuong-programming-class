#include <iostream>

using namespace std;

bool isSentencePalindrome(string s);

int main() {

    // cout << isPalindrome("abba") << endl; // 1
    // cout << isPalindrome("rotor") << endl; // 1
    // cout << isPalindrome("abcdba") << endl; // 0
    // cout << isPalindrome("ferrari") << endl; // 0

    // sử dụng kĩ thuật 2 pointers

    // h   |   t
    // a b | b a

    // if s[h] == s[t]: continue until center
    // if only 1 pair is not equal -> return false

    cout << isSentencePalindrome("senile felines!") << endl; // 1
    cout << isSentencePalindrome("8276se*&^nile fe(*&li_!*=))nes000!") << endl; // 1
    cout << isSentencePalindrome("s$^%ni$^%1le  ^%$ FeLin3$^%es345!") << endl; // 1


    return EXIT_SUCCESS;
}

bool isSentencePalindrome(string s) {
    int head = 0;
    int tail = s.length() - 1;

    while (head < tail) {
        // skip a few chars until we reach legit chars for head and tail
        while (!(s[head] >= 'a' && s[head] <= 'z')) {
            head++;
        }

        while (!(s[tail] >= 'a' && s[tail] <= 'z')) {
            tail--;
        }

        if (s[head] != s[tail]) return false;
        head++;
        tail--;
    }

    return true;

    

    // senile felines!

    // h                           t
    // s$^%ni$^%1le  ^%$ FeLin3$^%es345!
}