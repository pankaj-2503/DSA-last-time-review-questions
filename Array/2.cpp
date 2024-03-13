class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // no. of subarray with given sum
        int n=nums.size();
        int ans=0,sum=0;
        unordered_map<int,int>m;
        m[0]++;
        for(auto i:nums){
            sum+=i;
            if(m.count(sum-k)>0) ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};