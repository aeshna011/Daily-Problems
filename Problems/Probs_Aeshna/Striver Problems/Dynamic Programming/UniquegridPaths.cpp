// problem 62 (UNIQUE PATHS)

#include<iostream> 
using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    // using tabulation(bottom up approach)

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // write for base case
        dp[0][0] = 1;

        // then write for all cases
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

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