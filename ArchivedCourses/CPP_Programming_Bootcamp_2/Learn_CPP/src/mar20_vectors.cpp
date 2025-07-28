#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    vector<string> cars;

    cars.push_back("Ferrari");
    cars.push_back("Lamborghini");

    // modify
    // cars[0] = "Maybach";

    // for (int i = 0; i < cars.size(); i++) {
    //     cout << cars.at(i) << endl;
    // }

    for (string car : cars) {
        cout << car << endl;
    }

    cars.push_back("Mercedes");
    cars.pop_back();
    // cars.push_back(1); // error at compile time

    for (auto car : cars) {
        cout << car << endl;
    }

    // auto i = 1;

    // dangerous operation: segfault
    // cars[100] = "McLaren";
    // cout << cars[100];

    // cout << cars.at(10) << endl; // error: out of range

    // cars.clear();
    cout << cars.front() << " - " << cars.back() << endl;
    cout << cars.empty() << endl; // 0: false
    cout << cars.max_size() << endl;


    vector<vector<int>> phone_numbers;

    phone_numbers

    return 0;
}