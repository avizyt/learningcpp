/* Question 4.1 (ADM)
 The Grinch is given the job of partitioning 2n players into two teams of n
players each. Each player has a numerical rating that measures how good he or
she is at the game. The Grinch seeks to divide the players as unfairly as possible,
so as to create the biggest possible talent imbalance between the teams. Show
how the Grinch can do the job in O(n log n) time.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> ratings = {8, 1, 4, 10, 2, 7, 3, 9};
    int n = ratings.size() / 2;

    sort(ratings.begin(), ratings.end());

    int sumTeamA = accumulate(ratings.begin(), ratings.begin() + n, 0);
    int sumTeamB = accumulate(ratings.begin(), ratings.end(), 0);

    int imbalance = sumTeamA - sumTeamB;

    cout << "Team A rating: ";
    for (int i = 0; i < n; ++i)
    {
        cout << ratings[i] << " ";
    }
    cout << "\nTeam B rating: ";
    for (int i = 0; i < 2 * n; ++i)
    {
        cout << ratings[i] << " ";
    }
    std::cout << "\nTalent Imbalance: " << imbalance << std::endl;
    return 0;
}