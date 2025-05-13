//Memoisation
 int f(int index, vector<int>&nums, vector<int>&dp){
   if(index >= nums.size() - 1) return 0;
   if(dp[index] != -1) return dp[index] ;
    // further Jump = fJ
   int fJ = min( (int)nums.size()-1 , index + nums[index] );
   int minsteps =  INT_MAX;
   for(int nI = index+1; nI <= fJ ; ++nI){
     // X = subresult
     int X = f(nI,nums,dp);
     if(X != INT_MAX) 
       minsteps = min(minsteps, 1 + X);
   }
   return dp[index] = minsteps;
 }

int ff(vector<int>&nums){
  int n = nums.size();
  vector<int>dp(n,-1);
  return f(0,nums,dp);
}

//Tabulation
int ff(vector<int>&nums){
   int n = nums.size();
   vector<int>dp(n,INT_MAX);
   dp[0]=0;
   for(int i = 0; i<n; ++i){
     for(int j = 1; j<= nums[i] && i+j < n ; ++j){
      dp[i+j]=min(dp[i+j],dp[i]+1);
     }
   }
  return dp[n-1];
}

//Space Optimisation
int f(vector<int>&nums){
    int n = nums.size();
    int jumps = 0, farthest = 0, currEnd = 0;
    for(int i = 0 ; i<n-1;++i){
        farthest = max(farthest, i + nums[i]);
        if( i == currEnd) {
          ++jumps;
          currEnd = farthest;
        }
    }
  return jumps;
}

