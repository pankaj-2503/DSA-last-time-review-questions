class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // subarray max sum 
       int mxsum=nums[0];
       int cursum=mxsum;
        for(int i=1;i<nums.size();i++){
            cursum=max(cursum+nums[i],nums[i]);
            mxsum=max(mxsum,cursum);
           
        }
        return mxsum;
    }
};