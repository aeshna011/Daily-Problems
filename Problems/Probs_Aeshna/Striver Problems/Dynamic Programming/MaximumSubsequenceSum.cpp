// SPACE OPTIMIZATION USING TABULATION( BOTTOM UP APPROACH ) 
//thumb rule tabulation is reverse of memoization so will be from 0->n-1 index
// time complexity 0(n)
// space complexity 0(1)

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();

    int prev1=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int curr=0;
        int pick=nums[i];
        if(i>1) pick+=prev2;
        int nonpick=prev1;
        curr=max(pick,nonpick);
        prev2=prev1;
        prev1=curr;
    }

return prev1;
}



// TABULATION( BOTTOM UP APPROACH ) 
//thumb rule tabulation is reverse of memoization so will be from 0->n-1 index
// time complexity 0(n)
// space complexity O(n)

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n+1,0);

    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1) pick+=dp[i-2];
        int nonpick=dp[i-1];
        dp[i]=max(pick,nonpick);
    }

return dp[n-1];
}



// MEMOIZATION recursion  as we have to try all patterns and return maximum of it 
// recursive function batayega f(n-1) index se f(0) tak masimum subsequence sum kya hai
// time complexity O(n)
// space complexity O(n)+)(n)

int func(int i ,vector<int>&nums,vector<int>&dp){

if(i==0) return nums[0];//base case
if(i<0) return 0;  // base case 

if(dp[i]!=-1) return dp[i];



int pick=nums[i]+func(i-2,nums,dp);
int nonpick=0+func(i-1,nums,dp);
return  dp[i]=max(pick,nonpick);


}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n+1,-1);
int ans=func(n-1,nums,dp);
return ans;
}



// with doing recursion  as we have to try all patterns and return maximum of it 
// recursive function batayega f(n-1) index se f(0) tak masimum subsequence sum kya hai
// time complexity 2^n
// space complexity O(n)

int func(int i ,vector<int>&nums){

if(i==0) return nums[0];
if(i<0) return 0;

int pick=nums[i]+func(i-2,nums);
int nonpick=0+func(i-1,nums);
return max(pick,nonpick);


}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
int ans=func(n-1,nums);
return ans;
}