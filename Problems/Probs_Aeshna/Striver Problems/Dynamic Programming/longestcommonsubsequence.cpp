// tabulation 
// O(N*M) time and space complexity
// we will write the code by shifting index by 1 position     
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++){
            dp[0][m]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) 
                dp[i][j]=1+dp[i-1][j-1];

                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

                }
            }
        }
        return dp[n][m];
       
    }


// memoization using dp array
// time complexity O(N*M)   (subproblems)
// space complexity O(N*M) +O(N+M) 
    int func(int i, int j, string s, string t,vector<vector<int>>&dp) {

        if(i<0 || j<0 ) return 0;   //base case 

        if(dp[i][j]!=-1) return dp[i][j];

        if (s[i] == t[j])
            return  dp[i][j]=1 + func(i - 1, j - 1, s, t,dp);

        else
            return dp[i][j]= max(func(i-1 ,j, s, t,dp), func(i, j-1, s, t,dp));
        
    }
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
         return func(n-1,m-1,text1,text2,dp);
    }


// recursicve function which tells longest common subsequence from (n-1,m-1)->(0,0)   
   // time complexity 2^n+m
   // space complexity O(N+M)
    int func(int i, int j, string s, string t) {

        if(i<0 || j<0 ) return 0;   //base case 
        if (s[i] == t[j])
            return 1 + func(i - 1, j - 1, s, t);

        else
            return max(func(i-1 ,j, s, t), func(i, j-1, s, t));
        
    }
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();
         return func(n-1,m-1,text1,text2);
    }
