bool valid(string &A){
    if(A.length()>3) return false;
    if(A.length()>1 && A.front()=='0') return false;
    int val=stoi(A);
    return val>=0 && val<=255;
}
void computeIpAddress(string &A,vector<string>&s){
    for(int i=1;i<=3 && i<A.size();i++){
        string first=A.substr(0,i);
        if(valid(first)){
            for(int j=1;j<=3 && i+j<A.size();j++){
                 string second=A.substr(i,j);
                 if(valid(second)){
                     for(int k=1;k<=3 && i+j+k<A.size();k++){
                         string third=A.substr(i+j,k);
                         string fourth=A.substr(i+j+k);
                         if(valid(third) && valid(fourth)){
                             s.emplace_back(first+"."+second+"."+third+"."+fourth);
                         }
                         
                     }
                 }
            }
        }   
    }
}

vector<string> Solution::restoreIpAddresses(string A) {
    //valid ip address
    vector<string>s;
    computeIpAddress(A,s);
    return s;
}
