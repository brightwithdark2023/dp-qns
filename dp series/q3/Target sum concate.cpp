// Memoisation
class Solution {
private:
    int f(int index, vector<int>&nums, vector<vector<int>>&dp , int val){
        if(index== 0) {
            if(val == 0 && nums[0] == 0 ) return 2;
            if(val == 0 || val == nums[0] ) return 1;
           return 0;
        }
        if(dp[index][val] != -1) return dp[index][val];
        int np = f(index -1, nums, dp, val );
        int p = 0;
        if(nums[index] <= val)
        p = f(index -1, nums, dp , val - nums[index]);
        return dp[index][val] = np+p;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n   = nums.size();
        int sum = 0;
        for(int i = 0; i<n;i++) sum+=nums[i];
        if((sum+target)%2  )  return 0;
        if((sum-target)<0) return 0;
        if( sum+target < 0) return 0;
        if((sum-target )%2) return 0;
        int s1 = (sum+target)/2;
        vector<vector<int>>dp(n, vector<int>(s1+1, -1));
        return f(n-1, nums, dp, s1);
    }
};
