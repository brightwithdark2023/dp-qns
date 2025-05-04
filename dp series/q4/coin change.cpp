// memoisation
class Solution {
private:
    int f(int index, int amount, vector<int>&arr, vector<vector<int>>&dp){
        if(index==0) {
            if(amount%arr[0] == 0) return amount/arr[0] ; 
            else return 1e9;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int np = 0 + f(index-1, amount, arr, dp);
        int p = 1e9;
        if(arr[index]<= amount)
         p = 1 + f(index, amount-arr[index], arr,dp);
        return dp[index][amount] = min(p,np);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,amount,coins, dp);
        if(ans>= 1e9) return -1;
        return ans; 
    }
};
