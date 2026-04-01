class Solution {
public:
    bool isValid(string s) {
        stack<char> store_parentheses;
        int size_string = s.size();

        if(size_string == 1 || s[0] == '}' || s[0] == ')' || s[0] == ']') {
            return false;
        }


        for(int i = 0; i < size_string; i++ ){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                store_parentheses.push(s[i]);
            }
            if(s[i] == ')') {
                if(store_parentheses.empty() || store_parentheses.top() != '(') 
                    return false;
                else 
                    store_parentheses.pop();
                    continue;
            }

            if(s[i] == '}') {
                if(store_parentheses.empty() || store_parentheses.top() != '{' )
                    return false;
                else 
                    store_parentheses.pop();
                    continue;
            }

            if(s[i] == ']') {
                if(store_parentheses.empty() || store_parentheses.top() != '[')
                    return false;
                else 
                    store_parentheses.pop();
                    continue;
            }
        }

        if(store_parentheses.size() != 0) {
            return false;
        }
        
        return true;
    }
};
