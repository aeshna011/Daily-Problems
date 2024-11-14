// this question is similar to the base intution of maximum consequence sum 
// but here the array is circular so the first and the last element are adjacent to each other
// toh isliye sum mein first aur lst element include nhi krna this is the condition

// isme hum do temp array leke ek mein first element nahi lenge aur dosri mein last elemnt nahi lenge
// dono ko function se pass karenge aur jo maximum hoga wo answer hoga


class Solution {
public:
int  func(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<long int>dp(n+1,0);

    dp[0]=nums[0];
    for(int i=1;i<n;i++){
       long int pick=nums[i];
        if(i>1) pick+=dp[i-2];
       long int nonpick=dp[i-1];
        dp[i]=max(pick,nonpick);
    }

return dp[n-1];
}

    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];
    vector<int> temp1;
    vector<int> temp2;
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=n-1) temp2.push_back(nums[i]);
       
    }
       long int ans=max(func(temp1),func(temp2));
        return ans; 
    }
};