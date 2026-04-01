class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;

        if (s.size() < 2 ) {
            return false;
        }

        for(auto c: s) {
            if ( c == '[' || c == '{' || c == '(' ) {
                brackets.push(c);
            }

            if ( c == ']') {
                if(!brackets.empty()) {
                    if (brackets.top() == '[') {
                        brackets.pop();
                    }
                    else 
                        return false;
                }
                else 
                    return false;
            }

            if ( c == '}') {
                if(!brackets.empty()) {
                    if (brackets.top() == '{') {
                        brackets.pop();
                    }
                    else 
                        return false;
                }
                else 
                    return false;
            }

            if ( c == ')') {
                if(!brackets.empty()) {
                    if (brackets.top() == '(') {
                        brackets.pop();
                    }
                    else 
                        return false;
                }
                else {
                    return false;
                }
            }
        }

        return brackets.empty();
    }
};
