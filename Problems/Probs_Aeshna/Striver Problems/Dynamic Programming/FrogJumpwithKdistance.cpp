 // tabulation solution 
  ///TL- O(n*k)  (their are n subproblems and for each subproblem loop is running k times)
  // SC-O(N)
  
class Solution {
  public:
 
  int func(int k, vector<int>& arr,vector<int> & dp){

    dp[0]=0;
         int n=arr.size();
      for(int i=1;i<n;i++){
      int steps=INT_MAX;
      for(int j=1;j<=k;j++){
        
         if(i-j>=0)
         {
             int jump=dp[i-j]+abs(arr[i]-arr[i-j]);
          steps=min(steps,jump);
       
         }   
         dp[i]=steps;
      }
      }
      return dp[n-1];
      
  }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n+1,-1);
        int ans=func(k,arr,dp);
        return ans;
    }
};



// memoization solution 
  ///TL- O(n*k)  (their are n subproblems and for each subproblem loop is running k times)
  // SC-O(N)+O(n)
class Solution {
  public:

  int func(int i,int k, vector<int>& arr,vector<int> & dp){
      if(i==0) return 0;
      
      if(dp[i]!=-1) return dp[i];
      
      int steps=INT_MAX;
      for(int j=1;j<=k;j++){
        
         if(i-j>=0)
         {
             int jump=func(i-j,k,arr,dp)+abs(arr[i]-arr[i-j]);
          steps=min(steps,jump);
        
         }
      }                             
       return dp[i]=steps;
      
  }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n+1,-1);
        int ans=func(n-1,k,arr,dp);
        return ans;
    }
};



  //recursive solution 
  ///TL- O(K^N
  // SC-O(N)
class Solution {
  public:

  int func(int i,int k, vector<int>& arr){
      if(i==0) return 0;
      
      int steps=INT_MAX;
      for(int j=1;j<=k;j++){
        
         if(i-j>=0)
         {
             int jump=func(i-j,k,arr)+abs(arr[i]-arr[i-j]);
          steps=min(steps,jump);
             
         }
          
      }
      
      return steps;
      
  }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        int ans=func(n-1,k,arr);
        return ans;
    }
};