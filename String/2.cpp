
int longestSubstrDistinctChars (string s)
{
    // longest substring with all different characters
    unordered_map<char,int>m;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(m[s[i]]==0 || i==0){
            m[s[i]]=i;
        }else{
            int p=m.size();
            ans=max(ans,p);
            i=m[s[i]];
            m.clear();
        }
    }
    int p=m.size();
    ans=max(ans,p);
    return ans;
    
    
    
}