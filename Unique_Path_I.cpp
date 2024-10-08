//recursion
class Solution {
public:
    int solve(int i,int j, int m, int n){
        //base case 
        if(i>=m-1 && j>=n-1)return 1;
        if(i>=m)return 0;
        if(j>=n)return 0;
        
        //recurance relation
     

        return solve(i+1,j,m,n) + solve(i,j+1,m,n);

    }
    int uniquePaths(int m, int n) {
       return solve(0,0,m,n); 
    }
};

//memoization
class Solution {
public:
    int solve(int i,int j, int m, int n,vector<vector<int>> &dp){
        //base case 
        
        if(i>=m-1 && j>=n-1)return 1;
        
        if(i>=m)return 0;
        if(j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        dp[i][j]= solve(i+1,j,m,n,dp);

         dp[i][j]+=solve(i,j+1,m,n,dp);

         return dp[i][j];
    
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
       return solve(0,0,m,n,dp); 
    }
};

//tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
          dp[0][0]= 1;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = 1;
                else{
                    int up = 0,left=  0;
                    if(i>0)up = dp[i-1][j];
                    if(j>0)left = dp[i][j-1];

                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//space optimise

class Solution {                                                                      
public:
    int uniquePaths(int m, int n) {                                                
           vector<int> prev(n,0);
          
        
        for(int i = 0;i<m;i++){
            vector<int>curr(n,0);
            for(int j = 0;j<n;j++){
                if(i==0 && j==0) curr[j] = 1;
                else{
                    int up = 0,left = 0;
                    if(i>0)up = prev[j];
                    if(j>0)left = curr[j-1];
                  curr[j] = up+left;
                }
            }
           prev = curr;
        }
        return prev[n-1];
    }
};

//2nd approach
class Solution {
public:
    int uniquePaths(int m, int n) {
      int N = m+n-2;
      int R = min(m,n)-1;
      double res = 1;
      for(int i = 1;i<=R;i++){
          res = res*(N-R+i)/i;
      }   
     return (int)res;
    }
};
