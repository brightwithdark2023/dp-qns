class Solution {
private:
    int f(int index, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if (index == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }
        if (dp[index][target] != -1) return dp[index][target];
        
        int notpick = f(index - 1, arr, target, dp);
        int pick = 0;
        if (arr[index] <= target)
            pick = f(index - 1, arr, target - arr[index], dp);
            
        return dp[index][target] = notpick + pick;
    }

public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum < d || (sum + d) % 2 != 0) return 0;

        int s1 = (sum + d) / 2;
        vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));
        return f(n - 1, arr, s1, dp);
    }
};
