#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class SolutionOptimized {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        queue<tuple<string, int, int>> q;
        q.push({"", 0, 0});

        while (!q.empty()) {
            auto [curr, open, close] = q.front();
            q.pop();

            if (open == n && close == n) {
                result.push_back(curr);
            }
            if (open < n) {
                q.push({curr + "(", open + 1, close});
            }
            if (close < open) {
                q.push({curr + ")", open, close + 1});
            }
        }

        return result;
    }
};
