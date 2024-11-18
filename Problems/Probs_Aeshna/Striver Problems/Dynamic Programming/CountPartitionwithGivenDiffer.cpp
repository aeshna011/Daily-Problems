// since diference of subsets always equal to d    |s1-s2|=d
// and s1 is always greater than or equal to d
// so we need  to find in how many ways we ca divide array into two subsets following the abive conditions

// so indirectly we need to find subsets with sum(totalsum-d)/2;
//thus(totaalsum-d)>0 since sum cant be negative as all elements are positive
// and (totalsum-d) should be even as sum cant be some fraction

 
  int func(vector<int>&arr,int n,  int sum)
	{
        // Your code goes here
    
	 const int mod=1e9+7;
         vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
         
        if(arr[0]==0   )dp[0][0]=2;
        else dp[0][0]=1;
        
        if(arr[0]!=0 && arr[0]<=sum)  dp[0][arr[0]]=1;
        
         for(int i=1;i<n;i++){
             for(int target =0;target<=sum;target++){
                 
                 int nonpick=dp[i-1][target];
                 int pick=0;
                 if(arr[i]<=target){
                     pick=dp[i-1][target-arr[i]];
                     
                 }
                 dp[i][target]=(pick+nonpick)  % mod;
                
             }
             
         }
         return dp[n-1] [sum];
	}
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=arr[i];
        }
        
        if(totalsum-d<0 || (totalsum-d)&1!=0 ) return 0;
        int value=(totalsum-d)/2;
            return func(arr,n,value);
    }