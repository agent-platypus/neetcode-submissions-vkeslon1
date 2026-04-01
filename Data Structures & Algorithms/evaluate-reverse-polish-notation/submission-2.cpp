class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> curr;
        for(const string& c : tokens) {
            if (c == "+") {
                int a = curr.top();
                curr.pop();
                int b = curr.top();
                curr.pop();
                curr.push(b + a);
            }
            else if (c == "-") {
                int a = curr.top();
                curr.pop();
                int b = curr.top();
                curr.pop();
                curr.push(b - a);
            }
            else if (c == "/") {
                int a = curr.top();
                curr.pop();
                int b = curr.top();
                curr.pop();
                curr.push(b/a);
            }
            else if (c == "*") {
                int a = curr.top();
                curr.pop();
                int b = curr.top();
                curr.pop();
                curr.push(a * b);
            }
            else {
                curr.push(stoi(c));
            }
        }
        return curr.top();
    }
};
