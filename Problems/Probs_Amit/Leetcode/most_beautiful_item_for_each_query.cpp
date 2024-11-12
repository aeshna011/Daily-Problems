// Problem 2070 || Most Beautiful Item For Each Query

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        map<int, int> beautyMap;

        sort(items.begin(), items.end());

        for (const auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            beautyMap[price] = max(beautyMap[price], beauty);
        }

       
        int maxBeauty = 0;
        for (auto& i : beautyMap) {
            maxBeauty = max(maxBeauty, i.second);
            i.second = maxBeauty;
        }

        for (int x : queries) {
            auto it = beautyMap.upper_bound(x);
            if (it == beautyMap.begin()) {
                ans.push_back(0); 
            } else {
                --it;
                ans.push_back(it->second);
            }
        }

        return ans;
    }
};