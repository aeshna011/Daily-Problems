//tabulation
    int change(int amount, vector<int>& coins) {
          int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        for(int i=0;i<=amount;i++){     // for 0 index
            if(i%coins[0]==0)   dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                int nonpick=dp[i-1][tar];
                int pick=0;
                if(coins[i]<=tar){
                    pick=dp[i][tar-coins[i]];
                }
                dp[i][tar]=pick+nonpick;
            }
        }
        return dp[n-1][amount];
    }


//memoization using recursion
//time complexity 0(n*amount)
// sapce complexity O(N* amount) +O(amount)
int func(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
//base ccase return 1 or 0
if(i==0){
    if(amount%coins[0]==0) return 1;
    else return 0;
    
}
if(dp[i][amount]!=-1) return dp[i][amount];
int nonpick=func(i-1,amount,coins,dp);
int pick=0;
if(coins[i]<=amount){
    pick=func(i,amount-coins[i],coins,dp);
}
return  dp[i][amount]= pick+nonpick;


}
    int change(int amount, vector<int>& coins) {
            int n=coins.size();
            vector<vector<int>> dp(n,vector<int>(amount+1,-1));
            int ans=func(n-1,amount,coins,dp);
            return ans;
        
    }
};
