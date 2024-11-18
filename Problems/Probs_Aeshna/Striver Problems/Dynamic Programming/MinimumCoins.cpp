//space optimisation using tabulation (bottom up approach)
    /// time complexity more than n*amount 
    // space complexity O(amount)  single array
    int func(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> prev(amount+1,0);
        //checking for aall amount for 0 index 
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = 1e9;
        }
        for (int i = 1; i < n; i++) {
            vector<int>curr(amount+1,0);
            for (int target = 0; target <= amount; target++) {

                int nonpick = prev[target];
                int pick = 1e9;
                if (coins[i] <= target) {
                    pick = curr[target - coins[i]] + 1;
                }

                curr[target] = min(pick, nonpick);
            }
            prev=curr;
        }

        return prev[amount];
    }

    
// tabulation (bottom up approach)
/// time complexity more than n*amount
// space complexity n*amount (dp array)
int func(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    // checking for aall amount for 0 index
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
    }
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int nonpick = dp[i - 1][target];
            int pick = 1e9;
            if (coins[i] <= target)
            {
                pick = dp[i][target - coins[i]] + 1;
            }

            dp[i][target] = min(pick, nonpick);
        }
    }
    return
     dp[n - 1][amount];
}

// doing recusrion which tells the minimum no of coins from 0->n-1 index
//  which sum up to target
/// time complexity more than 2^n because we keep reamin at index
// space complexity O(target)
class Solution
{
public:
    int func(int i, int amount, vector<int> &coins)
    {

        if (i == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }

        int nonpick = func(i - 1, amount, coins);
        int pick = 1e9;
        if (coins[i] <= amount)
        {
            pick = 1 + func(i, amount - coins[i], coins); // whenever single value can be taken multiple times then 1 and keep standing at tht index
        }
        return min(pick, nonpick);
    }