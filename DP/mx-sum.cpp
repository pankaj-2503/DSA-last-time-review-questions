// given array find maximum sum of non adjacent element
//eg. Input
// 4
// 2 1 4 9 
// Output : 11

// recursive way
int solve(int index,vector<int>&nums){
    if(index==0) return nums[index];
    if(index<0) return 0;

    int pick=nums[index]+solve(index-2,nums);
    int notpick=0+solve(index-1,nums);
    return max(pick,notpick);
}
int maxNonAdjacentSum(vector<int>&nums){
    int n=num.size();
    return solve(n-1,nums);
}

// memoization
int solve(int index,vector<int>&nums,vector<int>&dp){
    if(index==0) return nums[index];
    if(index<0) return 0;
    // dp test case
    if(dp[index]!=-1) return dp[index];

    int pick=nums[index]+solve(index-2,nums,dp);
    int notpick=0+solve(index-1,nums,dp);
    return dp[index]=max(pick,notpick);
}
int maxNonAdjacentSum(vector<int>&nums){
    int n=num.size();
    vector<int>dp(n,-1);
    return solve(n-1,nums,dp);
}


//space optimization
int maxNonAdjacentSum(vector<int>&nums){
    int n=num.size();
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1) take+=prev2;
        int nottake=0+prev;
        int cur=max(take,nottake);
        prev2=prev;
        prev=cur;
    }
    return prev;
}
