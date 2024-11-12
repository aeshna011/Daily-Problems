//Problem #2285 || Maximum Total Importance Of Roads

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long int ans=0;
        vector<int> mp(n,0);
        for(long long int i=0;i<roads.size();i++){
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        long long int val=1;
        sort(mp.begin(),mp.end());
        for(long long int i=0;i<n;i++){
            ans+=(mp[i]*val);
            val++;
        }
        return ans;
    }
};
