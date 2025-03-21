#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> multiplyMatrices(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    // mat1 = {
    //     {1, 2, 3}, i = 0
    //     {4, 5, 6}  i = 1
    // };

    // mat2 = {
    //     {7, 8},  i = 0
    //     {9, 10}, i = 1
    //     {11, 12} i = 2
    // };

    // res = 
    // {
    //     {(1*7 + 2*9 + 3*11), (1*8 + 2*10 + 3*12)},
    //     {(4*7 + 5*9 + 6*11), (4*8 + 5*10 + 6*12)}
    // }   

    // [0, 0]
    // mat1: 0.0 - 0.1 - 0.2 
    // mat2: 0.0 - 1.0 - 2.0

    // [0, 1]
    // mat1: 0.0 - 0.1 - 0.2
    // mat2: 0.1 - 1.1 - 2.1

    // res = {
    //     {58, 64}, {139, 154}
    // }


    vector<vector<int>> res;

    // res[0][0] = 

    // for (int i = 0; i < mat1.size(); i++) {
    //     for (int j = 0; j < mat1[i].size(); j++) {
    //         // for (int k = 0; k < mat2[0].size(); k++) {
                
    //         // }
            
    //         cout << mat1[i][j] << endl;
    //     }
    // }

    int m1I = 0, m1J = 0, m2I = 0, m2J = 0, resI = 0, resJ = 0;

    // cout << "m1I = " << m1I << " resJ = " << resJ;

    int total;
    
    vector<int> row;
    
    for (int j = 0; j < 2; j++) {
        total = 0;
        for (int i = 0; i <= mat1.size(); i++) {
            int product = mat1[m1I][m1J] * mat2[m2I][m2J];

            cout << "mat1value = " << mat1[m1I][m1J] << " mat2 val = " << mat2[m2I][m2J] << endl;
            cout << "product = " << product << " - total = " << total << " index " << m1I << m1J << m2I << m2J << endl;

            total += product;

            // manually move the pointer of each matrix
            m1J++; // 0 -> 2
            m2I++;
        }
        m1J = 0;
        m2I = 0;
        m2J += 1;
        row.push_back(total);
        cout << endl;
    }

    res.push_back(row);
    
    m1I = 1;
    m1J = 0;
    m2I = 0;
    m2J = 0;

    for (int j = 0; j < 2; j++) {
        total = 0;
        for (int i = 0; i <= mat1.size(); i++) {
            int product = mat1[m1I][m1J] * mat2[m2I][m2J];

            cout << "mat1value = " << mat1[m1I][m1J] << " mat2 val = " << mat2[m2I][m2J] << endl;
            cout << "product = " << product << " - total = " << total << " index " << m1I << m1J << m2I << m2J << endl;

            total += product;

            // manually move the pointer of each matrix
            m1J++; // 0 -> 2
            m2I++;
        }
        m1J = 0;
        m2I = 0;
        m2J += 1;
        row.push_back(total);
        cout << endl;
    }
    
    res.push_back(row);

    cout << total << endl;

    return res;
}
