class Solution {
public:

//TABILATION APPROACH 
// WE WILL USE 3D DP ARRAY TO SOLVE BOTTOM UP APPROACH
// TIME COMPLEXITY N*M*M *9
// SPACE COMPLEXITY N*M*M

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
     // bottom case 
     // for fill 3d dp for n-1 row and alice and bob can be between columns 
        for (int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];  // (take once)
                else 
                dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];  //(take twice )
            }
        }
      
        int ans=0;

// NOW FILL DP FROM N-2 ROW TO 0 ROW
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){

  int maxi=INT_MIN;

// FOR EACH CELL  THEIR WILL NE 9 CASES

                      for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {

                    if(j1==j2){
                        ans=grid[i][j1];
                    }
                    else 
                    ans=grid[i][j1]+grid[i][j2];
                    
// IF THE COLUMN GO OUT OF BOUNDS SO ADD VERY LESS VALUE TO ANSWER 
                    if(j1+di<0 || j1+di>=m || j2+dj<0 || j2+dj>=m) 
                    ans+=-1e9;
                    else
                    ans+=dp[i+1][j1+di][j2+dj];

                    maxi=max(maxi,ans);
                }
            }
            dp[i][j1][j2]=maxi;     
               }
    }
}
return dp[0][0][m-1];
    }
};






// MEMOIZAATION WITH RECURSION WE WILL TRY OUT ALL THE PATHS TAKEN BY ALICE AND 
// BOB TOGETHER AND WILL RETURN MAXIMUM OF IT
//( FROM 0 ROW TO N-1 ROW)
// TIME COMPLEXITY N*M*M *9 SUBPROBLEMS
// SPACE COMPLEXITY O(N)
class Solution {
public:
   
int func(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
    
     int n = grid.size();
        int m = grid[0].size();


    if(i==n-1){ //base case
        if(j1==j2) return grid[n-1][j1]; // SIRF EK HI LENA H SAME COLUMN PAR 
        else return grid[n-1][j1]+grid[n-1][j2];
    }

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

// CHECK IF OUT OF BOUNDS 
    if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e9;

    int maxi=INT_MIN;

    // try out all the paths THEIR CAN BE 9 PATHS 
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){

int ans=0;

int newj1=j1+dj1;
int newj2=j2+dj2;

// check if new columns are within the column limit 
if(newj1>=0 && newj1<m &&  newj2>=0 &&  newj2<m ){

         //end up at same column
            if(j1==j2)
             ans= grid[i][j1] +func(i+1,j1+dj1,j2+dj2,grid,dp);

            else
             ans= grid[i][j1]+grid[i][j2]+func(i+1,j1+dj1,j2+dj2,grid,dp);
            maxi=max(maxi,ans); 
        }
    }
}
    return dp[i][j1][j2]=maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
      
             vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return func(0, 0, m - 1, grid,dp);
    }
};