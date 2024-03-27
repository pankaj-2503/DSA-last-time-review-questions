// find no. of subarray whose product is less than k
// Input: nums = [10,5,2,6], k = 100
// Output: 8

class Solution {
public:
    //sliding window approach
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0,left=0,right=0,prod=1;
        while(right<n){
            prod*=nums[right++];
            while(prod>=k && left<right) prod/=nums[left++];
            if(prod<k) cnt+=(right-left);
        }
        return cnt;
    }
};