class Solution {
public:
    bool isValid(string s) {
        // stack<char> store_parentheses;
        // int size_string = s.size();

        // if(size_string == 1 || s[0] == '}' || s[0] == ')' || s[0] == ']') {
        //     return false;
        // }


        // for(int i = 0; i < size_string; i++ ){
        //     if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
        //         store_parentheses.push(s[i]);
        //         continue;
        //     }
        //     if(s[i] == ')') {
        //         if(store_parentheses.empty() || store_parentheses.top() != '(') 
        //             return false;
        //         else 
        //             store_parentheses.pop();
        //             continue;
        //     }

        //     if(s[i] == '}') {
        //         if(store_parentheses.empty() || store_parentheses.top() != '{' )
        //             return false;
        //         else 
        //             store_parentheses.pop();
        //             continue;
        //     }

        //     if(s[i] == ']') {
        //         if(store_parentheses.empty() || store_parentheses.top() != '[')
        //             return false;
        //         else 
        //             store_parentheses.pop();
        //             continue;
        //     }
        // }

        // if(store_parentheses.size() != 0) {
        //     return false;
        // }

        // return true;



        stack<char> store_parentheses;
        int size_string = s.size();

        if(size_string == 1 || s[0] == '}' || s[0] == ')' || s[0] == ']') {
            return false;
        }

        unordered_map<char, char> pairs = {{')','('}, {']','['}, {'}','{'}};

        for(char c : s) {
            if(c == '(' || c == '[' ||  c == '{') {
                store_parentheses.push(c);
                continue;
            }
            
            auto it = pairs.find(c);
            if(it == pairs.end())
                return false;

            if(store_parentheses.empty() || store_parentheses.top() != it->second) 
                return false;
            store_parentheses.pop();
        }

        return store_parentheses.empty();
    }
};
