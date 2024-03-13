class Solution {
  public:
    int romanToDecimal(string &str) {
        // roman number to decimal conversion
        map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int sum=0;
        
        for(int i=0;i<str.size();i++){
            if(m[str[i]]<m[str[i+1]]){
                sum-=m[str[i]];
            }else
            sum+=m[str[i]];
        }
        return sum;
        
    }
};