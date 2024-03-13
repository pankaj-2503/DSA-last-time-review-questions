class Solution {
  public:
    string findSum(string X, string Y) {
        // find sum of two string which have large numbers eg. a="4323423434234234" ,b= "123434234234"
       
        long long j=Y.size()-1,i=X.size()-1;
        long long sum=0,carry=0;
        long long p=0;
        string ans;
        while(i>=0 || j>=0){
           if(i>=0){
               sum+=(X[i--]-'0');
           }
           if(j>=0){
               sum+=(Y[j--]-'0');
           }
           sum+=carry;
           ans.push_back(sum%10+'0');
           carry=sum/10;
           sum=0;
           
        }
        if(carry!=0) ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        while(ans.size()>=2 && ans[0]=='0') ans.erase(0,1);
        
       
        
        return  ans;
    }
};