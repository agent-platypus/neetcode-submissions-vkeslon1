#include <print>

class Solution {
public:

    vector<string> res;

    vector<string> generateParenthesis(int n) {
        string curr;
        dfs(n, curr, 0, 0);
        return res;
    }

    void dfs(int n, string& curr, int close, int open) {


        // print("curr string = {}\n", curr);
        if ( (close == open) && (open == n)) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr += '(';
            dfs(n, curr, close, open + 1);
            curr.pop_back();
        }

        if (close < open) {
            curr += ')';
            dfs(n, curr, close + 1, open);
            curr.pop_back();
        }

    }
};

// the generated parentheses must be well-formed
// always start with an opening bracket
