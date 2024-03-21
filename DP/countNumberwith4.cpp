// to find numbers of 4 present in between 1 to N in O(n) time

 int countNumberswith4(int N) {
         if(N<4) return 0;
         int d=log10(N);
         
         vector<int>dp(d+1); //dp[i] represent count of 4 from 1->(10^d-1)
         dp[0]=0,dp[1]=1;
         for(int i=2;i<=d;i++) dp[i]=dp[i-1]*9+ceil(pow(10,i-1));
         
         int p=ceil(pow(10,d));
         int msd=N/p; //most significant digit
         
         if(msd==4) return msd*dp[d] + (N%p)+1;
         
         if(msd>4) return (msd-1)*dp[d]+p+countNumberswith4(N%p);
         return msd*dp[d]+countNumberswith4(N%p);
    }