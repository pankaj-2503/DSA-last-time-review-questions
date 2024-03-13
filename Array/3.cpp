class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // max product subarray value
        int last=1,mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            last*=nums[i];
            mx=max(mx,last);
            if(last==0) last=1;
        }
        last=1;
        for(int i=nums.size()-1;i>0;i--){
            last*=nums[i];
            mx=max(mx,last);
            if(last==0) last=1;
        }
        return mx;
    }
};