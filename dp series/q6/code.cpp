// Memoisation
  bool f(int index , vector<int>&nums, vector<int>&dp ){
     if(index>=nums.size() -1 ) return true;
     if(dp[index]!=-1) return   dp[index];
     //furtherJump = fJ
     int fJ = min((int)nums.size()-1 , index+nums[index]);
     // nextIndex = nI
     for(int nI = index+1, nI <= fJ; ++nI){
       if(f(nI,nums,dp)) return dp[index]=true;
     }
     return dp[index]= false;
    }
 bool ff(vector<int>&nums){
    int n = nums.size();
   vector<int>dp(n,-1);
   return f(0,nums,dp);
 }

//Tabulation
 bool ff(vector<int>&nums){
   int n = nums.size();
   vector<int>dp(n,false);
   dp[n-1] = true;
   for(int i = n-2; i>=0; --i){
     int furthestjump = min(n-1 , i+ nums[i]);
     for(int j = i+1; j<=furthestjump; ++j){
           if(dp[j]){
             dp[i] = true;
             break;
           }
     }
   }
   return dp[0];
 }

//Space Optimisation
bool ff(vector<int>&nums){
  int n = nums.size();
  int reachable = 0; 
  for(int i = 0; i<n; ++i){
    if(i>reachable) return false;
    reachable = max(reachable, i+nums[i]);
  }
  return true;
}
