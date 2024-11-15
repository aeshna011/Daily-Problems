//tabulation
int findWays(vector<int>& arr, int k)
{
	 const int mod=1e9+7;
	 int n=arr.size();
         vector<vector<int>>dp(n+1,vector<int>(k+1,0));
         
         for(int i=0;i<n;i++){
             dp[i][0]=1;
         }
         if(arr[0]<=k)
         dp[ 0][arr[0]]=1;
         
         for(int i=1;i<n;i++){
             for(int target =0;target<=k;target++){
                 
                 int nonpick=dp[i-1][target];
                 int pick=0;
                 if(arr[i]<=target){
                     pick=dp[i-1][target-arr[i]];
                     
                 }
                 dp[i][target]=(pick+nonpick)  % mod;
                
             }
             
         }
         return dp[n-1] [k];
}



// using memoization  
// for count as base case arrives we either return 1 or 0
// tiem complexity O(n*k) subproblems
// space complexity O(N*K) +O(n)

const int mod=1e9+7;
	int func(int i,int arr[],int n,int sum,vector<vector<int>>&dp){
	    
	 
	    if(sum==0) return 1;
	    if(i==0)  {
	        if(arr[i]==sum) return 1;
	        else return 0;
	    }

	    if(dp[i][sum]!=-1) return dp[i][sum];
	    int nonpick=func(i-1,arr,n,sum,dp);
	    int pick=0;
	    if(arr[i]<=sum){
	        pick=func(i-1,arr,n,sum-arr[i],dp);
	    }
	    
	    return dp[i][sum]= (pick+nonpick ) %mod;
	}