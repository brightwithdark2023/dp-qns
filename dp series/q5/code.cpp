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

