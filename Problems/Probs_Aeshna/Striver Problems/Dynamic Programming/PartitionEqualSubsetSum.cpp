
// TIME COMPLEXITY O(N)+O(N*K) FOR DP AND SUM 

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if ((sum & 1) != 0) // sum is odd
            return false;

        else {
 

  // this is code to find if their exist a subsequence of target=sum/2 in nums array
  // if yes it means we have tow subsequences with sum/2 in nums 
  
            vector<vector<bool>> dp(n + 1, vector<bool>(sum/2 + 1, false));

            for (int i = 0; i < n; i++) {
                dp[i][0] = true;
            }

            if (nums[0] <= sum/2)
                dp[0][nums[0]] = true;

            for (int ind = 1; ind < n; ind++) {
                for (int k = 1; k <= sum/2; k++) {

                    bool nonpick = dp[ind - 1][k];

                    bool pick = false;
                    if (nums[ind] <= k) {
                        pick = dp[ind - 1][k - nums[ind]];
                    }

                    dp[ind][k] = pick || nonpick;
                }
            }

            return dp[n - 1][sum/2];
        }
    }
