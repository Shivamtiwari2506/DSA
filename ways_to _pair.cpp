//recursion 
class WaysToPairPeople {
public:
	int solve(int n) {
    		return solve(n-1) + ((n-1)*solve(n-2)); //recurrance relation
      }
};

//memoization
class WaysToPairPeople {
public:
	int solve(int n) {
    		vector<int>dp(n+1);
            dp[1] = 1;
            dp[2] = 2;
            for(int i = 3;i<=n;i++){
                  dp[i] = dp[i-1]+ ((i-1)*dp[i-2]);
            }
            return dp[n];
      }
};
