#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    long long total_sum = (long long)n * (n + 1) / 2; 
    long long arr_sum = 0;
 
    for (int i = 0; i < n - 1; ++i) {
        int num;
        cin >> num;
        arr_sum += num;  
    }
 
    cout << total_sum - arr_sum << endl; 
    return 0;
}