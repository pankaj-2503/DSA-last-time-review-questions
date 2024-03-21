  // from jump from 1,2,3 count no. of ways to reach top 
   long long countWays(int n)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 4;
        
        return (countWays(n-1) + countWays(n-2) + countWays(n-3)) %1000000007;
        
    }

    //memoization (top-down approach)
     long long solve(int n,vector<long long> &dp)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 4;
        
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(solve(n-1,dp) + solve(n-2,dp) + solve(n-3,dp))%1000000007;
    }
    long long countWays(int n)
    {
       vector<long long> dp(n+1,-1);
       return solve(n,dp);
    }

    //bottom up approach
    long long countWays(int n)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 4;
        
        vector<long long> dp(n+1);
        dp[0]=0,dp[1]=1,dp[2]=2,dp[3]=4;
        
        for(int i=4;i<=n;i++)
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000007;
        
        return (dp[n])%1000000007;
    }

    //best optimized approach
    int countWays(int N)
{
        //Create the array of size 3.
        int  ways[3] , n = N;
         
        //Initialize the bases cases
        ways[0] = 1;
        ways[1] = 1;
        ways[2] = 2;
         
        //Run a loop from 3 to n
        //Bottom up approach to fill the array
        for(int i=3 ;i<=n ;i++)
            ways[i%3] = ways[(i-1)%3] + ways[(i-2)%3] + ways[(i-3)%3];
         
        return ways[n%3];
}