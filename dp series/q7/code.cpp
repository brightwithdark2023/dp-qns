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
