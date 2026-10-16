class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthes;
        unordered_map<char, char> bracket_pairs = {
            {')', '('}, {'}', '{'}, {']', '['}
        };
        
        for(char currPar: s) {
            if (auto it = bracket_pairs.find(currPar); it == bracket_pairs.end()) { // closing brackets
                parenthes.push(currPar);
            }
            else {
                if (!parenthes.empty()) {
                    if (parenthes.top() == it->second) 
                        parenthes.pop();
                    else 
                        return false;
                }
                else {
                    return false;
                }
                
            }
            
        }

        return parenthes.empty();
    }
};
