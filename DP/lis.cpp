int lis(vector<int>nums){
    // to find longest increasing subsequence
    if(nums.size()<0) return 0;
    int n=nums.size();
    vector<int>ans(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                ans[i]=max(ans[i],ans[j]+1);
            }
        }
    }
    return *max_element(ans.begin(),ans.end());
}