//this problem is based on variable starting point and variable fixed point 

//PROBLEM STATEMENT 
// -- MINIMUM PATH SUM FROM ANY CELL OF FIRST ROW TO ANY CELL OF LAST ROW 

// WE WILL BE HERE USING TABULATION (BOTTOM UP APPROACH ) WHICH IS 0->N-1
//TL - O(n*n) +O(n)
// sc- O(n*n)

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    
 int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
   
    for (int j = 0; j < n; j++) {
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {

int up=0;
int rd=0;
int ld=0;
            if (i > 0)
                 up = matrix[i][j] + dp[i - 1][j];
            else
             up = matrix[i][j] + 1e9;

            if (j < n - 1)
                 rd = matrix[i][j] + dp[i - 1][j + 1];
            else
                 rd = matrix[i][j] + 1e9;

            if (j > 0)
                 ld = matrix[i][j] + dp[i - 1][j - 1];
            else
                 ld = matrix[i][j] + 1e9;

            dp[i][j] = min({up,rd,ld});
        }
    }
    int mini = 1e9;
    for (int j = 0; j < n; j++) {
        mini = min(mini, dp[n - 1][j]);
    }
    return mini;
}
}
;


 // using  space optimization using tabulation (bottom up approach)
    // time complexity O(n*n) O(n)

    // space complexity O(n)
    
class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
    
 int n = matrix.size();
        vector<int>prevrow(n,0);
   
    for (int j = 0; j < n; j++) {
        prevrow[j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++) {
        vector<int> curr(n,0);
        for (int j = 0; j < n; j++) {

int up=0;
int rd=0;
int ld=0;
            if (i > 0)
                 up = matrix[i][j] + prevrow[j];
            else
             up = matrix[i][j] + 1e9;

            if (j < n - 1)
                 rd = matrix[i][j] + prevrow[j+1];
            else
                 rd = matrix[i][j] + 1e9;

            if (j > 0)
                 ld = matrix[i][j] + prevrow[j-1];
            else
                 ld = matrix[i][j] + 1e9;

            curr[j]= min({up,rd,ld});
        }
        prevrow=curr;
    }
    int mini = 1e9;
    for (int j = 0; j < n; j++) {
        mini = min(mini, prevrow[j]);
    }
    return mini;
}
};



//base concept is recursion we will try all paths 


//using memoization (top down approach)   n-1->0
//time complexity n*n
//space complexity O(n) (NO OF ROWS) +O(n*n)
class Solution {
public:

    int func(int i, int j, int n, vector<vector<int>>& matrix,vector<vector<int>>&dp) {

        if (j < 0 || j > n - 1)
            return 1e9;

        if (i == 0)
            return matrix[0][j];

    if(dp[i][j]!=-1) return dp[i][j];

        int up = matrix[i][j] +func(i-1,j,n,matrix,dp);
        int rd=matrix[i][j]+func(i-1,j+1,n,matrix,dp);
        int ld=matrix[i][j]+func(i-1,j-1,n,matrix,dp);
        return dp[i][j]= min({up,rd,ld});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = 1e9;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));

        for (int j = 0; j < n; j++) {
            mini = min(mini,func(n-1,j,n,matrix,dp));
        }
        return mini;
    }
};
