#include <print>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;

        for(const auto& s: tokens) {
            if (!res.empty()) {

                // for each operation, 2 entries before the encounter with the 
                // operator char are summed 

                // the res also needs to be stored on the stack
                if (s == "+") {
                    int op1, op2;
                    op1 = res.top();
                    res.pop();
                    op2 = res.top();

                    res.pop();
                    res.push(op2 + op1);
                    continue;
                }
                else if (s == "-") {
                    int op1, op2;
                    op1 = res.top();
                    res.pop();
                    op2 = res.top();

                    res.pop();
                    res.push(op2 - op1);
                    continue;
                }
                else if (s == "/") {
                    int op1, op2;
                    op1 = res.top();
                    res.pop();
                    op2 = res.top();

                    res.pop();
                    res.push(op2 / op1);
                    continue;
                }

                else if (s == "*") {
                    int op1, op2;
                    op1 = res.top();
                    res.pop();
                    op2 = res.top();
                    res.pop();
                    res.push(op2 * op1);
                    continue;
                }


            }


            int numericEntries;
            from_chars(s.data(), s.data() + s.size(), numericEntries);
            res.push(numericEntries);

            
        }
        return res.top();
    }
};
