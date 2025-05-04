// Memoization:
class Solution {
private:
 int f(int index,vector<vector<int>>&dp, vector<int>&nums, int val){
        //edge case
        if(index==0) return (val%nums[0] == 0);
        if(dp[index][val]!= -1) return dp[index][val];
        int notpick = f(index-1,dp,nums, val);
        int pick = 0;
        if(nums[index]<=val)
        pick = f(index, dp, nums, val- nums[index]);
       return  dp[index][val]= notpick + pick ;
 }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        return f(n-1,dp,coins,amount);
    }
};
