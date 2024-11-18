    //SPACE OPTIMISED (CAPACITY)  
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int> prev(w+1,0);
    for(int i=0;i<=w;i++){
        prev[w]=(i/weight[0])*profit[0];
    }
    for(int i=1;i<n;i++){
        vector<int>curr(w+1,0);
        for(int j=0;j<=w;j++){
        int nonpick=prev[j];
          int pick=-1e9;   // it means this pue is never picked
          if(weight[i]<=j){
              pick=profit[i]+curr[j-weight[i]];
          }
        curr[j]=max(pick,nonpick);
        }
        prev=curr;
    }
   

return prev[w];


}


      // tabualtion 
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int i=0;i<=w;i++){
        dp[0][w]=(i/weight[0])*profit[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
        int nonpick=dp[i-1][j];
          int pick=-1e9;   // it means this pue is never picked
          if(weight[i]<=j){
              pick=profit[i]+dp[i][j-weight[i]];
          }
        dp[i][j]=max(pick,nonpick);
        }
    }
   

return dp[n-1][w];


}


//memoization using recursion since we have to see all combinations and get the maximum sum
// time complexity (n*capacity)
// time complexityb O(N*capacity ) +O(capacity)

int func(int i,vector<int>& profit, vector<int>& weight, int w,vector<vector<int>>&dp){
      if(i==0){
          
              return (w/weight[0])*profit[0];
          }
          if (dp[i][w]!=-1) return dp[i][w];

          int nonpick=func(i-1,profit,weight,w,dp);
          int pick=-1e9;   // it means this pue is never picked
          if(weight[i]<=w){
              pick=profit[i]+func(i,profit,weight,w-weight[i],dp);
          }
          return  dp[i][w]= max(pick,nonpick);
          
          
      }