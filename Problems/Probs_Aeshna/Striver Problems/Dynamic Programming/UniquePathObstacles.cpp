//PROBLEM 63 (Unique Paths II)

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//time complexity O(N*M)
// space complexity O(N*M)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1)
            return 0; // edge case

        dp[0][0] = 1; // write for base case(bottom )

        /// then write for all cases
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                else if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;

                else {
                    int up = 0;
                    int left = 0;

                    if (i > 0)
                        up = dp[i - 1][j];

                    if (j > 0)
                        left = dp[i][j - 1];

                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};