#include <bits/stdc++.h> 
int f(int index, int amount, vector<int>&a, vector<vector<int>>&dp){
    if(index == 0) {
        if(amount%a[0] == 0) return amount/a[0];
        else
        return 1e9;
    }
    if(dp[index][amount] != -1) return dp[index][amount];
    int notpick = 0+ f(index-1, amount, a, dp);
    int pick = 1e9;
    if(a[index] <= amount)
    pick = 1+ f(index, amount-a[index] , a, dp);
    return dp[index][amount] = min(pick , notpick);
}
int minimumElements(vector<int> &num, int amount)
{   int n = num.size();
    vector<vector<int>>dp(n, vector<int>(amount+1, -1));
    int ans = f(n-1, amount, num , dp);
    if(ans >= 1e9) return -1;
    return ans;