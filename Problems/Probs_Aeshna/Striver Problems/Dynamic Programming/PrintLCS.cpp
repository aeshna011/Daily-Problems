
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[0][m] = 0;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
          // now we have filled the dp array


        int i = n;
        int j = m;
        int length = dp[n][m];
        int index = length - 1;
        string ans = "";
        for (int i = 0; i < length; i++) {
            ans += '#';
        }
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                ans[index] = text1[i - 1];
                index--;
                i--;
                j--;

            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        cout<<ans;
        return dp[n][m];
    }
