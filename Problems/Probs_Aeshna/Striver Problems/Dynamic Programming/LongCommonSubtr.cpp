  // only difference is that in the dp array we set element to 0 if not equal and return the maximum answer which we have got
  int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp (n+1,vector<int> (m+1,0));
        // bottom case
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
            
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else {
                    dp[i][j]=0;
                }
            }
        }
        return ans;
        
    }

    // space optimisation method
    
     int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.length();
        int m=s2.length();
        vector<int >prev(m+1,0);
        // bottom case
      
        int ans=0;
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1,0);
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=1+prev[j-1];
                    ans=max(ans,curr[j]);
                }
                else {
                    curr[j]=0;
                }
            }
            prev=curr;
        }
        return ans;
        
    }