// Leetcode problem 64  (Minimum path Sum)

#include<iostream> 
using namespace std;
#include <bits/stdc++.h>


//USING TABULATION 
// TIME COMPLEXITY O(N*M)
//SPACE COMPLEXITY O(N*M)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0]; // write for base case (bottom condition)

        for (int i = 0; i < m; i++) { // then write for all cases
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                    
                else {
                    int up = 0;
                    int left = 0;

                    if (i > 0)
                        up = grid[i][j] + dp[i - 1][j];
                    else
                        up = grid[i][j]+1e9;

                    if (j > 0)
                        left = grid[i][j] + dp[i][j - 1];
                    else 
                      left = grid[i][j] + 1e9;

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
