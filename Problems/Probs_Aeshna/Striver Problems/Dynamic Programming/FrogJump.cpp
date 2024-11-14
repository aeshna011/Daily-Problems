
  //space optimised tabulation solution  (bottom up)
  // TL- O(n)  
  // SC- O(1)
  // THIS FUNCTION WILL TELL MINIMUM ENERGY FROM STAIR 0 to N-1 
  class Solution {
  public:
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
       
        int prev1=0;
        int prev2=0;
        
        for(int i=1;i<n;i++){
            
            int one =prev1+abs(height[i]-height[i-1]);
            int two=INT_MAX;
            if(i>1) two=prev2+abs(height[i]-height[i-2]);
            int curr=min(one,two);
            prev2=prev1;
           prev1=curr;
        }
        return prev1;
      
    }
};
  

  //tabulation solution  (bottom up)
  // TL- O(n)  
  // SC- O(N)
  // THIS FUNCTION WILL TELL MINIMUM ENERGY FROM STAIR 0 to N-1 
  class Solution {
  public:
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int one =dp[i-1]+abs(height[i]-height[i-1]);
            int two=INT_MAX;
            if(i>1) two=dp[i-2]+abs(height[i]-height[i-2]);
            dp[i]=min(one,two);
            
        }
        return dp[n-1];
      
    }
};




  //memoization solution  (top down)
  // TL- O(n)  (no of subprobkems)
  // SC- O(N)+O(n)
  // THIS FUNCTION WILL TELL MINIMUM ENERGY FROM STAIR N-1 TO STAIR 0
  
// class Solution {
//   public:
  
//   int func(int i,vector<int> &height,vector<int> &dp){
//       if(i==0)  return 0;
      
//       if(dp[i]!=-1) return dp[i];
      
//       if(i==1) return dp[1]=abs(height[1]-height[0]);
      
//       int two=INT_MAX;
      
//      int one=func(i-1,height,dp)+abs(height[i]-height[i-1]);
     
//      if(i>1) two=func(i-2,height,dp)+abs(height[i]-height[i-2]);
//       return  dp[i]= min(one,two);
      
//   }
//     int minimumEnergy(vector<int>& height, int n) {
//         // Code here
//         vector<int> dp(n+1,-1);
//         int ans=func(n-1,height,dp);
//         return ans;
        
//     }
// };





//recursive solution  (top down)
  // TL- O(2^n)
  // SC- O(N)
  // THIS FUNCTION WILL TELL MINIMUM ENERGY FROM STAIR N-1 TO STAIR 0
// class Solution {
//   public:
  
//   int func(int i,vector<int> &height){
//       if(i==0)  return 0;
//       if(i==1) return abs(height[1]-height[0]);
      
//       int two=INT_MAX;
      
//      int one=func(i-1,height)+abs(height[i]-height[i-1]);
     
//      if(i>1) two=func(i-2,height)+abs(height[i]-height[i-2]);
//       return min(one,two);
      
//   }
//     int minimumEnergy(vector<int>& height, int n) {
//         // Code here
        
//         int ans=func(n-1,height);
//         return ans;
        
//     }
// };

