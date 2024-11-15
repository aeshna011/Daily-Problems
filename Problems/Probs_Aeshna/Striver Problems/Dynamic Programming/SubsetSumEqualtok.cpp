
  //SPACE OPTIMIZATION TABULATION   (BOTTOM UP APPROACH) FIRST 
  // TIME COMPLEXITY O(N*K)
  // SAPCE COMPLEXITY O(K)
  
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<bool>prev(target+1,false);
        prev[0]=true;
        
        if(arr[0]<=target) prev[arr[0]]=true;
            
        for(int ind=1;ind<n;ind++){
            vector<bool>curr(target+1,false);
            curr[0]=true;
            for(int k=1;k<=target;k++){
                
                bool nonpick=prev[k];
                
                bool pick=false;
                if(arr[ind]<=k){
                    pick=prev[k-arr[ind]];
                }
                
                curr[k]=pick || nonpick;
                
            }
            prev=curr;
        }
        return prev[target];
        
    }
};



// } Driver Code Ends
  //TABULATION   (BOTTOM UP APPROACH) FIRST 
  // ->WRITING RFOR BOTTOM CASE AND THEN WRITE FOR ALL CASES AND THEN COPY RECURSION  :)
  // TIME COMPLEXITY O(N*K)
  // SAPCE COMPLEXITY O(N*K)
  
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        if(arr[0]<=target)
        dp[0][arr[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            for(int k=1;k<=target;k++){
                
                bool nonpick=dp[ind-1][k];
                
                bool pick=false;
                if(arr[ind]<=k){
                    pick=dp[ind-1][k-arr[ind]];
                }
                
                dp[ind][k]=pick || nonpick;
                
            }
        }
        
        return dp[n-1][target];
        
    }
};



// MEMOIZATION recursion  by trying all subsequence and checking if exist a subsequence whose sum is equal to target 
  // time complexity  N*K
  // space complexity O(N)+O(N*K)
  
  bool func(int ind, int target,vector<int>& arr,vector<vector<bool>>&dp ){
      
      //base case
      if(target==0) return true;       
      
      //kyunki arr[0] par matlab hai ki subsequence exist karti hai kya target ke equal
      if(ind==0)  return arr[0]==target;  // it means that it returns true
                                         // if arr[0]==target
                                         
      if(dp[ind][target]!=false) return dp[ind][target];
      
      bool nonpick=func(ind-1,target,arr,dp);
      
      bool pick=false;
      if(arr[ind]<=target){
          pick=func(ind-1,target-arr[ind],arr,dp);
      }
      
      //agar inme se koi true degi toh haan hai
      return dp[ind][target]=pick|| nonpick;
      
  }







// doing recursion  by trying all subsequence and checking if exist a subsequence whose sum is equal to target 
// func(n-1,target) tells if their exists a subsequence from 0 to n-1 index whose sum is equal to target
  // time complexity  2^n
  // space complexity O(N)
  
  bool func(int ind, int target,vector<int>& arr ){
      
      //base case
      if(target==0) return true;       
      
      //kyunki arr[0] par matlab hai ki subsequence exist karti hai kya target ke equal
      if(ind==0)  return arr[0]==target;  // it means that it returns true
                                         // if arr[0]==target
      
      bool nonpick=func(ind-1,target,arr);
      
      bool pick=false;
      if(arr[ind]<=target){
          pick=func(ind-1,target-arr[ind],arr);
      }
      
      //agar inme se koi true degi toh haan hai
      return pick ||nonpick;
      
  }