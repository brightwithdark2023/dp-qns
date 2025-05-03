class Solution
{

    unordered_map<string, vector<string>> memo;

    vector<string> backtrack(int open, int close, int n)
    {
        string key = to_string(open) + "," + to_string(close);
        if (memo.count(key))
            return memo[key];

        if (open == n && close == n)
            return {""};

        vector<string> result;
        if (open < n)
        {
            for (string s : backtrack(open + 1, close, n))
            {
                result.push_back("(" + s);
            }
        }
        if (close < open)
        {
            for (string s : backtrack(open, close + 1, n))
            {
                result.push_back(")" + s);
            }
        }

        return memo[key] = result;
    }

public:
    vector<string> generateParenthesis(int n)
    {
        return backtrack(0, 0, n);
    }
};
