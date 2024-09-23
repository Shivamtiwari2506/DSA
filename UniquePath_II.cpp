//recursion == TLE
class Solution {
public:
     
     int helper(int i ,int j, int m, int n,vector<vector<int>> &arr){
       
        if(i==m-1 && j==n-1 && arr[i][j]!=1)return 1;
        if(i>=m || j>=n || arr[i][j]==1 || arr[m-1][n-1]==1)return 0;
        
         
         int down= 0,right = 0;
           down = helper(i+1,j,m,n,arr);
        
           right = helper(i,j+1,m,n,arr);
      

        return down+right;

     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return helper(0,0,m,n,obstacleGrid);
    }
};

//memoization
#include <vector>
using namespace std;
class Solution {
public:
    int rat(vector<vector<int>>& a, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1  && a[i][j] != 1) {
            return 1;
        }
        if (i >= m || j >= n || a[i][j] == 1 || a[m-1][n-1] == 1) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
       
        int right = rat(a, m, n, i, j + 1, dp); 
        int down = rat(a, m, n, i + 1, j, dp); 
        dp[i][j] = right + down;
        return right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        int result = rat(obstacleGrid, m, n, 0, 0, dp);
        return result;
    }
};
