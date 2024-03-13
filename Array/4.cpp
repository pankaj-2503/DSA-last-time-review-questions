class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // no. of subarray sum divisible by k
        int n=nums.size();
        int sum=0,cnt=0;
        unordered_map<int,int>m;
        m[0]++;
        for(auto i:nums){
            sum+=i;
            int remainder=sum%k;
            if(remainder<0) remainder=remainder+k;
            cnt+=m[remainder];
            m[remainder]++;
        }
        return cnt;
    }
};