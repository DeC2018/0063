#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        // dp[i][j] := unique paths from (0, 0) to (i - 1, j - 1)
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        dp[0][1] = 1;  // Can also set dp[1][0] = 1

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m][n];
    }
};

int main() {
    Solution solution;

    vector<vector<int>> obstacleGrid1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << "Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]" << endl;
    cout << "Output: " << solution.uniquePathsWithObstacles(obstacleGrid1) << endl;

    vector<vector<int>> obstacleGrid2 = {{0, 1}, {0, 0}};
    cout << "Input: obstacleGrid = [[0,1],[0,0]]" << endl;
    cout << "Output: " << solution.uniquePathsWithObstacles(obstacleGrid2) << endl;

    return 0;
}
