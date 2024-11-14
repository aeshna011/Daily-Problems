
//tabulation solution (bottom up)
// time complexity O(n)  
//  space compexity 0(n)

class Solution {
public:
    int func(int n, vector<int>& dp) {

        dp[0] = 1;
        dp[1] = 1; // write for base cases

        // then write for all cases
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];

        
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        int ans = func(n, dp);
        return ans;
    }
};





// SPACE OPTIMIZES tabulation solution (bottom up)
// time complexity O(n)  
//  space compexity 0(1)

class Solution {
public:
    int func(int n) {

       int prev2 = 1;
        int prev1 = 1; // write for base cases

        // then write for all cases
        for (int i = 2; i <= n; i++) {
            int curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;

        }

        return prev1;

        
    }
    int climbStairs(int n) {
       
        int ans = func(n);
        return ans;
    }
};