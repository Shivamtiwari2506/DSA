//recursive solution'
class Solution {
public:
    int result = INT_MAX;
    void fun(vector<vector<int>>& grid,int i,int j,int sum, int m,int n){
        //base case
        if(i==m-1 && j==n-1){
            sum+=grid[i][j];
            result = min(result,sum);
            return;
        }
        if(i==m ||j==n)return;
        // recurance relation
        sum+=grid[i][j];
        fun(grid,i+1,j,sum,m,n);
        fun(grid,i,j+1,sum,m,n);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        fun(grid, 0,0,0,m,n);
        return result;
    }
};  
//TLE
//2nd approach memoization
class Solution {
public:
        int result= INT_MAX;
    void fun(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j,
            int m, int n, int sum) {
           //base case
            if(i==m-1 && j==n-1){
                sum+=grid[i][j];
                dp[i][j] = grid[i][j];
                result = min(sum,result);
            }
            if(i==m || j==n)return;
            if(dp[i][j]!=-1){
                sum+=dp[i][j];
                result = min(sum,result);
                return;
            }
            
        //    recurance relation
              sum+=grid[i][j];
               int down = INT_MAX, right = INT_MAX;

               
               if(i+1<=m-1 && j<=n-1){
                    fun(grid,dp,i+1,j,m,n,sum);
                    down = grid[i][j]+dp[i+1][j];
               } 
               if(j+1<=n-1 && i<=m){
               fun(grid,dp,i,j+1,m,n,sum);
               right = grid[i][j]+dp[i][j+1];
               }

               dp[i][j] = min(down,right);

         }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        fun(grid, dp, 0, 0, m, n, 0);
        return result;
    }
};
//3rd space optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == 0 && j == 0) continue;
                    int left = INT_MAX, up = INT_MAX;
                    if (i > 0) left = grid[i - 1][j];
                    if (j > 0) up = grid[i][j - 1];
                    grid[i][j] = grid[i][j] + (min(left, up));
                }
            }
            return grid[m - 1][n - 1];
    }
};
