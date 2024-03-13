string Solution::solve(string A, string B) {
    // bulls and cows
    int n=A.size();
    int bull=0,cow=0;
    unordered_map<char,int>m;
    for(int i=0;i<n;i++){
         m[A[i]]++;
    }
    for(int i=0;i<n;i++){
        if(A[i]==B[i]) {bull++;m[A[i]]--;}
    }
    for(int i=0;i<n;i++){
        if(A[i]!=B[i] && m[B[i]]){
            cow++;m[B[i]]--;
        }
    }
    string ans=to_string(bull)+"A"+to_string(cow)+"B";
    return ans;
}
