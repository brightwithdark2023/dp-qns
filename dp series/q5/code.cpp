 //  Kadane's Algorithm
//Space Optimization
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int test = nums[0];
            int maxsum =nums[0];
            for(int i = 1;i<n;i++){
                    test =max(nums[i],nums[i]+test);
                    maxsum = max(maxsum, test);
            }
        return maxsum;
    }
};

//Tabulation
class Solution{
public:
      int maxSubArray(vector<int>&nums){
        int n = nums.size();
        vector<int>dp(n);
        int maxsum = nums[0];
         dp[0] = nums[0];
        for(int i = 1; i<n;i++ ){
          dp[i] = max(nums[i],nums[i]+dp[i-1]);
          maxsum = max(maxsum, dp[i]);
        }
        return maxsum;
      }
};

//Memoisation
class Solution{
   int f(int i, vector<int>&nums,  vector<int>&dp, int&maxsum){
      if(i>= nums.size()) return 0;
      if(dp[i] != INT_MIN) return dp[i];
              dp[i]  =  max(nums[i], nums[i]+f(i+1,nums, dp, maxsum));
              maxsum = max(maxsum, dp[i]);
      return dp[i];
   }
public:
    int maxSubArray(vector<int>&nums){
       int n = nums.size();
       vector<int>dp(n,INT_MIN);
        int maxsum = nums[0];
         f(0,nums,dp,maxsum);
       return maxsum;
    }
};

