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
