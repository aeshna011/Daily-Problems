// PARTITION ARRAY INTO TWO SUBSETS SUCH THAT  DIFFERENCE OF ABSOLUTE DIFFERENCE OF THEIR SUM IS MINIMUM

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.'
	
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

            if (arr[0] <= sum)
                dp[0][arr[0]] = true;

            for (int i = 1; i < n; i++) {
                for (int target = 1; target <= sum; target++) {
                    bool nonpick = dp[i - 1][target];
                    bool pick = false;
                    if (arr[i] <= target) {
                        pick = dp[i - 1][target - arr[i]];
                    }
                    dp[i][target]=pick || nonpick;
                }
            }

            long mini = INT_MAX;
            for (long total = 0; total <= sum / 2; total++){
                if(dp[n-1][total]==true){
                    long s1 = total;
                    long s2 = sum - total;
                    mini = min(mini, abs(s2 - s1));
                }
            }
            return mini;
}
