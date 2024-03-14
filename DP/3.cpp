int knapsack(int weight,int wt[],int val[],int n){
    // 0-1 knapsack to find max profit for storing weight equal to weight
    vector<vector<int>>k(n+1,vector<int>(w+1));
    for(int i=0;i<=n;i++){
        for(int w=0;w<=weight;j++){
            if(i==0 || w==0) k[i][w]=0;
            else if(wt[i-1]<=weight){
                k[i][w]=max(k[i-1][w],k[i-1][weight-w]+val[i-1]);
            }
            else k[i][w]=k[i-1][w];
        }
    }
    return k[n][weight];
}