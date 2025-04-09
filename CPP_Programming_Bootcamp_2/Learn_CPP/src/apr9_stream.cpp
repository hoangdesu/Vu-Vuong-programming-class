#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

    // 1. bỏ data vào stream
    ostringstream out_str_stream;

    out_str_stream << "Vuong" << " " << "Nguyen";

    cout << out_str_stream.str() << endl;

    if (out_str_stream.good()) {
        cout << "Good stream" << endl;
    }

    // out_str_stream.flush(); // neccessary for large data

    // 2. lấy data ra từ stream
    istringstream in_str_stream(out_str_stream.str());

    string fname, lname;

    in_str_stream >> fname;
    in_str_stream >> lname;

    // cin >> var;

    cout << "Last name: " << lname << endl;
    cout << "First name: " << fname << endl;


    return 0;
}



ADT: abstract data types (built on top of arrays)
queue.enqueue(item)
queue.dequeue() // item at the beginning of the queue (first item)

stack.push(item)
stack.pop() // item on top (last item)


line << name
queue.enqueue(name)


// char[] s
// vector<char> => char[]
// string => vector<char>
// => build dua tren static array => contiguous block of memory


// string stream: string buffer => non-sequential


// {[({ask( )jdhksdhjkaj skajd akjs ...})]}