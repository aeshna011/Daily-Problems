#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long int n,ans=0;
    cin>>n;
    vector<long long int> arr(n);
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(long long int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            ans+=(arr[i-1]-arr[i]);
            arr[i]=arr[i-1];
        }
    }
    cout<<ans;
    return 0;
}
