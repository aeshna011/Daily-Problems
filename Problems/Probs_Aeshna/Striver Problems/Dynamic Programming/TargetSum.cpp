// it is similar to partition array into 2 subsets with common difference 

    int CountSubsets(vector<int>& arr, int n, int sum) {
        // Your code goes here
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= sum)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= sum; target++) {

                int nonpick = dp[i - 1][target];
                int pick = 0;
                if (arr[i] <= target) {
                    pick = dp[i - 1][target - arr[i]];
                }
                dp[i][target] = (pick + nonpick) % mod;
            }
        }
        return dp[n - 1][sum];
    }

int findTargetSumWays(vector<int>& nums, int target) {
    int n =nums.size();
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=nums[i];
    }
    if((totalsum-target<0) || ((totalsum-target)&1) !=0) return 0;
    int ans=CountSubsets(nums,n,(totalsum-target)/2);
    return ans;
}




//take all patterns of subsequences by recursion
//time complexity 2^n
// space complexity O(N)
    int find(int i, vector<int>& nums, int sum, int target) {

        if (i < 0) {
            if (sum == target)
                return 1;
            else
                return 0;
        }

        int pos = find(i - 1, nums, sum - nums[i], target);
        int neg = find(i - 1, nums, sum + nums[i], target);

        return pos + neg;
    }