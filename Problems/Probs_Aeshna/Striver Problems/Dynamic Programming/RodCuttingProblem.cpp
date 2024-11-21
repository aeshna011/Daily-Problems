 //space optimization tabulation solution 
// time complexity O(n^2)
// space complexity O(n^2)
    int cutRod(int price[], int n) {
        
        vector<int>prev(n+1,0);  //rodlength array
        for(int i=0;i<=n;i++){
            prev[i]  =i*price[0];
        }
        for(int i=1;i<n;i++){
            vector<int> curr(n+1,0);
            for(int j=0;j<=n;j++){
                int nontake=prev[j];
                int take=INT_MIN;
                int rodlength=i+1;
                if(rodlength<=j){
                    take=price[i]+curr[j-rodlength];
                }
                curr[j]=max(take,nontake);
            }
            prev=curr;
        }
        
        
        return prev[n];

    }
};

//tabulation solution 
// time complexity O(n^2)
// space complexity O(n^2)
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=i*price[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int nontake=dp[i-1][j];
                int take=INT_MIN;
                int rodlength=i+1;
                if(rodlength<=j){
                    take=price[i]+dp[i][j-rodlength];
                }
                dp[i][j]=max(take,nontake);
            }
        }
        
        
        return dp[n-1][n];

    }
};

  // recursive solution more than 2^n 
  // as at each position we have more than 2 options 
  // space complesxity O(rodlength)
  int f(int ind,int n,int price[] ){
      if(ind==0){
          return n*price[0];
      }
      int nottake=0+f(ind-1,n,price);
      int take=INT_MIN;
      int rodlength=ind+1;
      if(rodlength<=n){
      take=price[ind]+f(ind,n-rodlength,price);
      
      }
      return max(take,nottake);
  }
    int cutRod(int price[], int n) {
        int ind=n;
           return f(ind-1,n,price);
    }
};
