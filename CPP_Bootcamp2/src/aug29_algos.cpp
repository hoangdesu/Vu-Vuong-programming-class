#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> accumulate;
    
    for (int i = 0; i < nums.size(); i++) {
        int key = nums[i];
        int acc = target - key;
        if (accumulate.find(acc) != accumulate.end()) {
            // cout << "has" << i << endl;
            return vector<int>{i, accumulate[acc]};
        } else {
            accumulate[key] = i;
        }
    }

    for (auto it = accumulate.begin(); it != accumulate.end(); it++) {
        cout << "key: " << it->first << " - value: " << it->second << endl;
    }

    
    
    return vector<int>{0, 0};
}

bool valid_parentheses(string s);

vector<int> shuffle(const vector<int>& nums) {

}



int main() {
    
    // nums = [2,7,11,15], target = 26
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = twoSum(nums, 26);

    // res.back()

    // removed_char = res.pop_back()
    

    // cout << res[0] << res[1];

    // Stacks
    // Valid parenthesis

    // ADT

    // "[({[([])]})]" => true
    // "(ab[c{de(f) 1} 2 ]_){}[{}]" => true
    // "({)[}]" => false   

    string test_cases[] = {"[({[([])]})]", "(ab[c{de(f) 1} 2 ]_){}[{}]", "({)[}]"};
    for (string tc : test_cases) {
        cout << "case " tc << ": " << valid_parentheses(tc) << endl;
    }

    cout << valid_parentheses("(ab[c{de(f) 1} 2 ]_){}[{}]") << endl;
    cout << valid_parentheses("({)[}]") << endl;
    cout << valid_parentheses("[({[([])]})]") << endl;


    pares = ['[', '(', '{', '[', '('] => []

    ([{}])

    push: ( [ {

    pop: } -> {, ] -> [, ) -> (

    if list is empty -> true

    char last_char = pairs[pairs.size() - 1];
    pairs.pop_back()
    if last_char != c:
        return false


        Challenges:
            1. apply unorderedmap into parens
            2. shuffle
    

    shuffle({1, 2, 3, 4}) -> {3, 2, 4, 1}

    return 0;
}