//problem 78 ||Subsets
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void solve(vector<int> out,vector<int> nums,vector<vector<int>>&answer,int size,int i){
        
        if(i>=size){
            answer.push_back(out);
            return;
        }
        solve(out,nums,answer,size,i+1);
        out.push_back(nums[i]);
        solve(out,nums,answer,size,i+1);
    }    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> out;
    int i=0;
    vector<vector<int>> answer;
    int size=nums.size();
    solve(out,nums,answer,size,i);
    return answer;    
    }
};