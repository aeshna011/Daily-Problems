// Problem 242 || Valid Anagram
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int size_1 = s.length();
        int size_2 = t.length();

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int res = s.compare(t);
        if(res==0){
            return true;
        }
        else{
            return false;
        }
    }
};
