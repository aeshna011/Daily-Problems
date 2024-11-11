// Problem 120  
//MINIMUM PATH SUM IN TRIANGUALR ARRAY GRID

#include <iostream> 
using namespace std;
#include <bits/stdc++.h>

class Solution {
public:

// using tabulation which is bottom up approach 
//time complexity 0(n*n) 
//space complexity O(n*N)

    int func(int i, int j, int n, vector<vector<int>>& triangle,
    vector<vector<int>> &dp) {


//here tabulation will be from n-1 to 0

//write for the base condition 
       for(int i=0;i<n;i++){
        dp[n-1][i]=triangle[n-1][i];
       }

//write for all cases
    for(int i=n-2;i>=0;i--){
        for(j=i;j>=0;j--){

        int down = triangle[i][j] + dp[i+1][j];
        int diagonal = triangle[i][j] + dp[i+1][j+1];
        dp[i][j]= min(down, diagonal);

        }
    }
       return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int ans = func(0, 0, n, triangle,dp);
        return ans;
    }
};

