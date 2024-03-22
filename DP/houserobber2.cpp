//memoization
class Solution {
public:
    int helper(int i ,vector<int>& nums,int n, vector<int>&dp)
    {
        if(i>n)  return 0;      //base case
      
        if(dp[i]!=-1)return dp[i];  //check if already evaluated for that value of i

        int pick = nums[i]+ helper(i+2 ,nums ,n,dp);
        int notpick = helper(i+1,nums,n,dp);  //to skip that house
        return dp[i]=max(pick ,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<int>dp(n,-1);  
        int fHouse = helper(0,nums,n-2,dp); //if we want to take first house
        for(int i=0;i<n;i++)
        {
            dp[i]=-1;  //changing values of dp back to -1
        }
        int notFirstHouse = helper(1,nums,n-1,dp); //if we want to take last house
        return max(fHouse,notFirstHouse);
    }
};

//bottom up approach
class Solution {
public:
    int houseRobber(vector<int>& nums) {
        // dynamic programming - decide each problem by its sub-problems:
        int dp[nums.size()+1];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i=2; i<nums.size(); i++)
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        return dp[nums.size()-1];
    }
    
    int rob(vector<int>& nums) {
        // edge cases:
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        // either use first house and can't use last or last and not first:
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(houseRobber(v1), houseRobber(v2));
    }
};