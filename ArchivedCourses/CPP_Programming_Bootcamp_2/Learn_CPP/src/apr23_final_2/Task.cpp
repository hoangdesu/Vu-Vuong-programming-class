#include "Task.h"
#include <vector>

using namespace std;

vector<int> findMultiples(const vector<vector<int>> &numbers, int multiple)
{
    vector<int> res;

    for (vector<int> row : numbers)
    {
        for (int num : row)
        {

            bool exists = false;

            for (int number : res)
            {

                if (num == number)
                {
                    exists = true;
                    break;
                }
            }

            if (!exists)
            {
                if (num % multiple == 0)
                {
                    res.push_back(num);
                }
            }
        }
    }
    return res;
}
