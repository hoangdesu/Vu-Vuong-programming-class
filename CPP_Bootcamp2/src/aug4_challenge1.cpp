#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> calculateTotalScores(vector<vector<int>> &scores)
{
	vector<int> results;
	for (auto row : scores)
	{
		int total = 0;
		for (int score : row)
		{
			total += score;
		}
		results.push_back(total);
	}
	return results;
}


void challenge_Q5()
{
    vector<vector<int>> scores = {
        {10, 20, 30}, 
        {40, 50, 60}, 
        {70, 80, 90} 
    };
		
		vector<int> totalScore = calculateTotalScores(scores);
		
		for (int score : totalScore)
		{
			cout << score << " ";
		}

}

// void flipVectors(scores)

int main(void)
{
    challenge_Q5();

    return EXIT_SUCCESS;
}