// LOGIC FOR MOST OPTIMISED SINGLE ARRAY 
// AS WE KNOW THAT CURR NEEDS PREVIOUS WT-WEIGHT[I]  (IF IT IS PICKED) TO UPDATE
// SO IF FILLING ELEMENTS FROM RIGHT TO LEFT IN CURRENT ARRAY , THEN THE RIGHT ELEMENTS IN THE PREV ARRAY WILL BE OF NO USE 
//  SO LOGICALLY THINKING IF WE FILL THE ELEMENTS IN THE PREV ROW ONLY FROM RIGHT TO LEFT  AND KEEP UPDATING ANSWER VALUE 
//  AS WE NEED ONLY THE LEFT ELEMENTS FROM THAT POSITION 
 int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<int> prev(maxWeight+1,0);
  for (int i = weight[0]; i <= maxWeight; i++) {
    prev[i] = value[0];
  }
  for (int i = 1; i <= n - 1; i++) {
    for (int wt =maxWeight; wt>=0; wt--) {
      int nonpick = prev[wt];
      int pick = INT_MIN;
      if (weight[i] <= wt) {
        pick = value[i] + prev[wt - weight[i]];
      }
      prev[wt] = max(pick, nonpick);
    }
	
  }
  return prev[maxWeight];
}


// space optimization O(maxweight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<int> prev(maxWeight+1,0);
  for (int i = weight[0]; i <= maxWeight; i++) {
    prev[i] = value[0];
  }
  for (int i = 1; i <= n - 1; i++) {
	  vector<int> curr(maxWeight+1,0);
    for (int wt =0; wt<=maxWeight; wt++) {
      int nonpick = prev[wt];
      int pick = INT_MIN;
      if (weight[i] <= wt) {
        pick = value[i] + prev[wt - weight[i]];
      }
      curr[wt] = max(pick, nonpick);
    }
	prev=curr;
  }
  return prev[maxWeight];
}


//TABULATION(BOTTOM UP )
//TIME COMPLEXITY (N*MAXWEIGHT)
// SPACE COMPLEXITY O(N*MAXWEIGHT)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
  // for every 0 index if the weight is less than maxweight we will return value[0] (BOTTOM CASE)
  for (int i = weight[0]; i <= maxWeight; i++) {       
    dp[0][i] = value[0];
  }
  for (int i = 1; i <= n - 1; i++) {             //index 0 is already done
    for (int wt = 0; wt <= maxWeight; wt++) {     //maxweigtht cwill be 0->max as in recursion it was opposite 
      int nonpick = dp[i - 1][wt];
      int pick = INT_MIN;
      if (weight[i] <= wt) {
        pick = value[i] + dp[i - 1][wt - weight[i]];
      }
      dp[i][wt] = max(pick, nonpick);
    }
  }
  return dp[n - 1][maxWeight];
}


//MEMOIZATION   (USING DP ARRAY)
// time complexity O(N*MAXWEIGHT) SUBPROBLEMS 
// space complexity O(N) + O(N*MAXWEIGHT)
int func(int i, int maxWeight, vector<int> &weight, vector<int> &value,vector<vector<int>>&dp) {
  if (i == 0) {
    if (weight[0] <= maxWeight)
      return value[0]; // index 0 par aake agar uss weight
                       // ko utha sakte hain toh hum usko le lenge
    else
      return 0;
  }
  if(dp[i][maxWeight]!=-1) return dp[i][maxWeight];
  int nonpick = func(i - 1, maxWeight, weight, value,dp);
  int pick = INT_MIN; // INT_MIN because it means  we never picked this item
  if (weight[i] <= maxWeight) {
    pick = value[i] + func(i - 1, maxWeight - weight[i], weight, value,dp);
  }
  return dp[i][maxWeight]= max(pick, nonpick);
}


// for trying out all possibilities we do recursion and this func(n-1,wt) tells that from  (0->n-1)index wo kitna total paisa chura 
// sakta hai with capacity of weight
// time complexity 2^n
// space complexity O(N)
int func(int i, int maxWeight, vector<int> &weight, vector<int> &value) {
  if (i == 0) {
    if (weight[0] <= maxWeight)             // index 0 par aake agar uss weight ko utha sakte hain toh hum usko lenge
      return value[0];                             
    else 
    return 0;
  }
  
  int nonpick = func(i - 1, maxWeight, weight, value);
  int pick = INT_MIN; // INT_MIN because it means  we never picked this item
  if (weight[i] <= maxWeight) {
    pick = value[i] + func(i - 1, maxWeight - weight[i], weight, value);
  }
  return max(pick, nonpick);
}