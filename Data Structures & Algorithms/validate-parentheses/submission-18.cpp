class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        // only push opening brackets
        // on encounters with closing brackets, check the top
        // also need to check if the stack is empty

        for(char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                parentheses.push(c);
            }

            else if (!parentheses.empty()) {
                if (c == ')') {
                    if (parentheses.top() == '(') {
                        parentheses.pop();
                        continue;
                    }
                    else {
                        return false;
                    }
                }

                else if (c == ']') {
                    if (parentheses.top() == '[') {
                        parentheses.pop();
                        continue;
                    }
                    else {
                        return false;
                    }
                }

                else if (c == '}') {
                    if (parentheses.top() == '{') {
                        parentheses.pop();
                        continue;
                    }
                    else {
                        return false;
                    }
                }
            }
            else {
                return false;
            }
             
        }

        return parentheses.empty();
    }
};
